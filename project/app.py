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

# Configure the showcase basic informations
STUDIO = {
    "studio_name" : "default_name",
    "studio_address" : "default_address",
    "studio_telephone" : "default_telephone",
    "studio_email" : "default_email",
    "studio_instagram" : "default_instagram",
    "studio_openhours" : "default_openhours",
}
def get_studio():
    try:
        infos = db.execute("SELECT * FROM studio WHERE id = ?", 1)[0]
        STUDIO["studio_name"] = infos["name"]
        STUDIO["studio_address"] = infos["address"]
        STUDIO["studio_telephone"] = infos["telephone"]
        STUDIO["studio_email"] = infos["email"]
        STUDIO["studio_instagram"] = infos["instagram"]
        STUDIO["studio_openhours"] = infos["openhours"]
    except ValueError:
        return 400

@app.before_request
def create_tables():
    # The following line will remove this handler, making it
    # only run on the first request
    app.before_request_funcs[None].remove(create_tables)
    get_studio()


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Route par défaut pour rediriger vers le site vitrine
@app.route('/', methods=["GET"])
def index():
    return render_template('/showcase/index.html', infos=STUDIO)


# Servir les fichiers du site vitrine
@app.route("/booking", methods=["GET", "POST"])
def booking():
    return render_template("/showcase/booking.html")

@app.route("/studio", methods=["GET"])
def studio():
    return render_template("/showcase/studio.html")

@app.route("/galerie", methods=["GET"])
def galerie():
    return render_template("/showcase/galerie.html")

@app.route("/artistes", methods=["GET"])
def artistes():
    return render_template("/showcase/artistes.html")

@app.route("/faq", methods=["GET"])
def faq():
    return render_template("/showcase/faq.html")

@app.route("/infos", methods=["GET"])
def infos():
    return render_template("/showcase/infos.html")


# Servir les fichiers de l'interface d'administration
@app.route("/admin/index")
def admin_index():
    return render_template("/admin/index.html")

@app.route("/admin/clients", methods=["GET"])
def clients():
    return render_template("/admin/client.html")

@app.route("/admin/rdv", methods=["GET"])
def rdv():
    return render_template("/admin/rdv.html")

@app.route("/admin/team", methods=["GET"])
def team():
    return render_template("/admin/team.html")

@app.route("/admin/kpi", methods=["GET"])
def kpi():
    return render_template("/admin/kpi.html")

@app.route("/admin/finance", methods=["GET"])
def finance():
    return render_template("/admin/finances.html")

@app.route("/admin/artists", methods=["GET"])
def artists():
    return render_template("/admin/artists.html")

@app.route("/admin/gallery", methods=["GET"])
def gallery():
    return render_template("/admin/gallery.html")

@app.route("/admin/parameters", methods=["GET"])
def parameters():
    return render_template("/admin/parameters.html")


@app.route("/change_settings", methods=["GET", "POST"])
def change_settings():
    request.form.get()
