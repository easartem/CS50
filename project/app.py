import os
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify, send_from_directory
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

# Configure application
app = Flask(__name__)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///tattooshop.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response



# Route par défaut pour rediriger vers le site vitrine
@app.route('/')
def index():
    return render_template('/showcase/index.html')

@app.route("/booking", methods=["GET", "POST"])
def booking():
    return render_template("/showcase/booking.html")



@app.route("/studio", methods=["GET"])
def studio():
    return render_template("studio.html")

@app.route("/galerie", methods=["GET"])
def galerie():
    return render_template("galerie.html")

@app.route("/artistes", methods=["GET"])
def artistes():
    return render_template("artistes.html")

@app.route("/faq", methods=["GET"])
def faq():
    return render_template("faq.html")

@app.route("/infos", methods=["GET"])
def infos():
    return render_template("infos.html")
