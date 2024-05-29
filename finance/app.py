import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/manage", methods=["POST"])
@login_required
def manage():
    if request.method == "POST":
        if not request.form:
            print("no form")
        else:
            print("form exist")
        print(request.form.get("share-value-3"))
        # # for transaction in transactions:
        # #     if new_value != 0:
        # #         db.execute("INSERT INTO transactions)
        # #         db.execute("UPDATE users")
        return jsonify(success=True), 200
    return jsonify(success=False, error="An error message"), 400


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    if request.method == "POST":
        if not portfolio:
            return (apology("not yet written"), 400)
        return (apology("portfolio exists"), 400)
    else:
        try:
            user_id = session["user_id"]
            portfolio = db.execute(
                "SELECT id, symbol, SUM(shares) AS sum FROM (SELECT * FROM transactions WHERE user_id=?) GROUP BY symbol", user_id)
            grand_total = 0
            cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]
            for stock in portfolio:
                #  stock.symbol
                #  stock.shares
                stock["price"] = 0
                # lookup actual price
                price = lookup(stock["symbol"])["price"]
                stock["price"] = price
                # compute total value
                total = float(price)*stock["sum"]
                stock["total"] = total
                grand_total = grand_total + total
                stock["nb_to_trade"] = 0
        except:
            return (apology("index error"))

        return render_template("index.html", rows=portfolio, cash=usd(cash["cash"]), grand_total=usd(grand_total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # if symbol is blank or does not exist (lookup) return apology
        if not request.form.get("symbol"):
            return apology("must provide symbol name", 400)
        elif not lookup(request.form.get("symbol")):
            return apology("must provide a valid symbol name", 400)
        symbol = request.form.get("symbol")
        price = lookup(request.form.get("symbol"))["price"]

        # if nb of shares is not a positive integer return apology
        if not request.form.get("shares"):
            return apology("must provide a valid shares number", 400)
        shares = request.form.get("shares")
        try:
            shares = int(shares)
        except ValueError:
            return apology("must provide a integer for shares number", 400)
        if shares <= 0:
            return apology("must provide a positive shares number", 400)

        # if purchase price (lookup) > user cash (query db) return apology
        purchase_price = price*shares
        user_id = session["user_id"]
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        user_cash = user_cash[0]["cash"]
        if purchase_price > user_cash:
            return apology("you don't have enough cash", 400)

        # else insert purchase into new table, and update user cash
        new_user_cash = user_cash - purchase_price
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_user_cash, user_id)
        db.execute("INSERT INTO transactions (symbol, price_per_share, shares, user_id) VALUES(?, ?, ?, ?)",
                   symbol, price, shares, user_id)

        # Redirect user to home page
        return redirect("/")
    else:
        return render_template("buy.html")


"""
    CREATE TABLE transactions (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
                               symbol TEXT NOT NULL,
                               price_per_share NUMERIC NOT NULL,
                               shares INTEGER NOT NULL,
                               date DATE DEFAULT CURRENT_TIMESTAMP NOT NULL,
                               user_id INTEGER NOT NULL,
                               FOREIGN KEY(user_id) REFERENCES users(id));
"""


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    try:
        rows = db.execute(
            "SELECT * FROM transactions WHERE user_id = ? ORDER BY date ASC", session["user_id"])
    except ValueError:
        return apology("history query failed", 400)
    return render_template("history.html", rows=rows)


# For each row, make clear whether a stock was bought or sold and include the stock’s symbol, the (purchase or sale) price,
# the number of shares bought or sold, and the date and time at which the transaction occurred.
# You might need to alter the table you created for buy or supplement it with an additional table. Try to minimize redundancies.
"""
    ALTER TABLE transactions ADD type BOOLEAN;
    UPDATE transactions SET type=TRUE WHERE shares>0;
    UPDATE transactions SET type=FALSE WHERE shares<=0;
"""


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol name", 400)
        elif not lookup(request.form.get("symbol")):
            return apology("must provide a valid symbol name", 400)
        quote = lookup(request.form.get("symbol"))
        return render_template("quoted.html", quote=quote)
    else:
        if not request.form.get("symbol"):
            return render_template("quote.html")
        else:
            return apology("problem with the lookup", 400)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # VERIFY THE EXISTENCE OF A USER INPUT -----------------
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure password confirmation is the same
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("password confirmation doesn't match", 400)

        # VERIFY THE VALIDITY OF THE USER INPUT -----------------
        # Query database for username already existing, Ensure username is unique
        name = request.form.get("username")
        psw = generate_password_hash(request.form.get("password"))
        try:
            new_user_id = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", name, psw)
        except ValueError:
            return apology("username already exists", 400)

        # Log in the user
        session["user_id"] = new_user_id

        # Redirect user to home page
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol") or not request.form.get("shares"):
            return apology("Must provide symbol and number", 400)

        if not lookup(request.form.get("symbol")):
            return apology("must provide a valid symbol name", 400)

        # if symbol not in listofsymbol:

        symbol = request.form.get("symbol")
        nb_to_sell = int(request.form.get("shares"))
        try:
            int(nb_to_sell)
        except ValueError:
            return apology("must provide a valid sell number", 400)

        nb_owned = db.execute(
            "SELECT SUM(shares) AS sum FROM (SELECT * FROM transactions WHERE user_id=? AND symbol=?)", session["user_id"], symbol)[0]
        nb_owned = int(nb_owned["sum"])
        if nb_to_sell <= 0 or nb_to_sell > nb_owned:
            return apology("you don't have enough shares", 400)

        # Selling the shares ---------------------------------------------------------------
        price = lookup(request.form.get("symbol"))["price"]
        gain = float(price)*nb_to_sell
        new_nb = nb_owned - nb_to_sell
        print(type(price))
        try:
            db.execute("INSERT INTO transactions (symbol, price_per_share, shares, user_id) VALUES(?, ?, ?, ?)",
                       symbol, price, -nb_to_sell, session["user_id"])
        except ValueError:
            msg = str(symbol) + str(price) + str(new_nb) + str(session["user_id"])
            return apology(msg, 400)

        # Updating the user cash  ----------------------------------------------------------
        try:
            cash = db.execute("SELECT cash FROM users WHERE id=?", session["user_id"])[0]
            new_cash = float(cash["cash"]) + gain
            db.execute("UPDATE users SET cash=? WHERE id=?", new_cash, session["user_id"])
        except ValueError:
            return apology("problem with cash update", 400)
        return redirect("/")
    else:
        try:
            stock_owned = db.execute(
                "SELECT symbol, SUM(shares) AS sum FROM (SELECT * FROM transactions WHERE user_id=?) GROUP BY symbol", session["user_id"])
        except ValueError:
            return apology("failed to retrieve the information from db, try again later", 400)
        # give list of stocks through argument
        return render_template("sell.html", stock_owned=stock_owned)
