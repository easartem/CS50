import os
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

# Configure application
app = Flask(__name__)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
# db = SQL("sqlite:///../project/tattooshop.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/clients", methods=["GET"])
def clients():
    return render_template("client.html")

@app.route("/rdv", methods=["GET"])
def rdv():
    return render_template("rdv.html")

@app.route("/team", methods=["GET"])
def team():
    return render_template("team.html")

@app.route("/kpi", methods=["GET"])
def kpi():
    return render_template("kpi.html")

@app.route("/finance", methods=["GET"])
def finance():
    return render_template("finances.html")

@app.route("/artists", methods=["GET"])
def artists():
    return render_template("artists.html")

@app.route("/gallery", methods=["GET"])
def gallery():
    return render_template("gallery.html")

@app.route("/parameters", methods=["GET"])
def parameters():
    return render_template("parameters.html")
