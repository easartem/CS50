import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
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


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method =="POST":
        # if symbol is blank or does not exist (lookup) return apology
        if not request.form.get("symbol"):
            return apology("must provide symbol name", 403)
        elif not lookup(request.form.get("symbol")):
            return apology("must provide a valid symbol name", 403)
        symbol = request.form.get("symbol")
        price = lookup(request.form.get("symbol"))["price"]

        # if nb of shares is not a positive integer return apology
        if not request.form.get("shares"):
            return apology("must provide a valid shares number", 403)
        shares = request.form.get("shares")
        try:
            shares = int(shares)
        except ValueError:
            return apology("must provide a integer for shares number", 403)
        if shares <= 0:
            return apology("must provide a positive shares number", 403)

        # if purchase price (lookup) > user cash (query db) return apology
        purchase_price = price*shares
        user_id = session["user_id"]
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        if purchase_price > user_cash:
            return apology("you don't have enough cash", 403)

        # else insert purchase into new table, and update user cash
        new_user_cash = user_cash - purchase_price
        db.execute("UPDATE users SET cash = ? WHERE id = ?", (new_user_cash, user_id))

        db.execute("", )

        return apology("TODO")
    else:
        return render_template("buy.html")

    CREATE TABLE transactions (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
                               symbol TEXT NOT NULL,
                               price_per_share NUMERIC NOT NULL,
                               shares INTEGER NOT NULL,
                               date DATE DEFAULT sysdate NOT NULL,
                               user_id FOREIGN KEY )


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

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
             return apology("must provide symbol name", 403)
        quote = lookup(request.form.get("symbol"))
        return render_template("quoted.html", quote=quote)
    else:
        if not request.form.get("symbol"):
            return render_template("quote.html")
        else:
            return apology("problem with the lookup", 403)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # VERIFY THE EXISTENCE OF A USER INPUT -----------------
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure password confirmation is the same
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("password confirmation doesn't match", 403)

        # VERIFY THE VALIDITY OF THE USER INPUT -----------------
        # Query database for username already existing, Ensure username is unique
        name = request.form.get("username")
        psw = generate_password_hash(request.form.get("password"))
        try :
            new_user_id = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", name, psw)
        except ValueError:
            return apology("username already exists", 403)

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
    return apology("TODO")
