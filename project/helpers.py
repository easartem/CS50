def initialize_table_studio():
    studio_name = "Tattoo Studio"
    studio_address = "00 rue du tatouage, Paris, France"
    studio_telephone = "01 23 45 67 88"
    studio_email = "info_studio@gmail.com"
    studio_instagram = "url de l'instagram du studio"
    studio_openhours = "10h-13h & 15h-20h"

    try:
        db.execute("INSERT INTO studio (name, address, telephone, email, instagram, openhours) VALUES (?, ?, ?, ?, ?, ?)",
                    studio_name, studio_address, studio_telephone, studio_email, studio_instagram, studio_openhours)
    except ValueError:
        return 400
    return
