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
    if request.method == "POST":
        # retrieve mandatory fields value
        fullname = request.form.get("fullname")
        phone = request.form.get("phone")
        email = request.form.get("email")

        # check for mandatory fields completion state
        if not fullname or not phone or not email:
            print('Mandatory fields are empty')

        # check for mandatory fields correct form submission

        # retrieve the rest of the form

        description = request.form.get("description")
        location = request.form.get("location")
        size = request.form.get("size")
        availability = request.form.get("availability")
        artist = request.form.get("artist")
        medium = request.form.get("medium")
        print("All fields have been retrieved !")
        print(fullname, phone, email)
        print(description, location, size)
        # insert new form into database
        try:
            #db.execute()
            pass
        except ValueError:
            return 400
        return render_template("/showcase/booking.html", infos=STUDIO)
    else:
        return render_template("/showcase/booking.html", infos=STUDIO)

@app.route("/studio", methods=["GET"])
def studio():
    return render_template("/showcase/studio.html", infos=STUDIO)

@app.route("/galerie", methods=["GET"])
def galerie():
    return render_template("/showcase/galerie.html", infos=STUDIO)

@app.route("/artistes", methods=["GET"])
def artistes():
    return render_template("/showcase/artistes.html", infos=STUDIO)

@app.route("/faq", methods=["GET"])
def faq():
    return render_template("/showcase/faq.html", infos=STUDIO)

@app.route("/infos", methods=["GET"])
def infos():
    return render_template("/showcase/infos.html", infos=STUDIO)


# Servir les fichiers de l'interface d'administration
@app.route("/admin")
def admin_index():
    return render_template("/admin/index.html", indos=STUDIO)

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

@app.route("/admin/parameters", methods=["GET", "POST"])
def parameters():
    if request.method == "POST":
        # Get the new values from the admin interface
        # if not new_name |  new_hours |  new_location |  new_tel |  new_mail |  new_insta:
        #     return 400
        # if empty field or no modification made return msg
        print("entered again")
        if not request.form:
            print("no form")
        if not request.form.get("shop-name"):
            print("error")
        new_name = request.form.get("shop-name")
        new_hours = request.form.get("shop-hours")
        new_location = request.form.get("shop-location")
        new_tel = request.form.get("shop-tel")
        new_mail = request.form.get("shop-mail")
        new_insta = request.form.get("shop-insta")

        # Update the global informations directly into the database
        db.execute("UPDATE studio SET name=?, address=?, telephone=?, email=?, instagram=?, openhours=? WHERE id=?;", new_name, new_location, new_tel, new_mail, new_insta, new_hours, 1)

        get_studio()
        return render_template("/admin/parameters.html", infos=STUDIO)
    else:
        return render_template("/admin/parameters.html", infos=STUDIO)


#def alert(message, type):

