# Tattoo Studio Booking Management
#### Video Demo:  <URL HERE>
#### Description:
Welcome to the repository for the Tattoo Studio website. The goal of this project is to create a website to help managing and promoting a tattoo studio.
It includes a comprehensive website with a user-friendly interface, an admin panel for managing the site, and features such as appointment booking and online payments.
Since the actual size of this project is quite big, I have implemented the basic pages, functions and routes to get a first mock-up. Further functions will be added during the completion
of CS50’s Web Programming with Python and JavaScript.

## Table of Contents

- [Technologies Used](#technologies-used)
- [Architecture](#architecture)
- [Usage](#usage)
- [Contact](#contact)

## Technologies Used

1. Front-end technologies
- **HTML/CSS** : Structure and design of the pages
- **JavaScript** : For dynamic interactions and advanced functionalities
- **Frameworks Bootstrap** : For responsive and aesthetic design

2. Back-end technologies

- **Python** with **Flask** : For the back-end and APIs
- **Database**: SQLite
- **API used**:
    - **Payments**: Square API (coming soon)
    - **Bookings**: Square API (coming soon)

3. Infrastructure & Deployment
- **During development:** cs50.dev
- **Hosting**: To be determined but most likely AWS or Heroku

## Architecture

### Global structure

The showcase website and admin panel both originate from the same root file: app.py.
By leveraging Flask, we create distinct routes to handle different sections of the site, ensuring a seamless navigation experience.
This centralized approach not only simplifies the architecture but also allows for a single database connection, enhancing data management and integration.

### The showcase website
The showcase website is a multi-page site designed to present the tattoo studio and its art to clients. It has two main goals: to present the tattoo artists, their styles, and works, and to allow potential clients to contact the studio with a detailed form about their personal projects. The features include:

- **Homepage**: A welcoming page with information about the studio.
- **Studio**: Detailed information about the studio.
- **Artists**: Detailed information about the artists.
- **Portfolio**: Gallery showcasing previous tattoo work.
- **FAQ**: Answers about frequently asked questions.
- **Infos**: Information about incoming guest.
- **Booking**: Contact form for inquiries.


### The admin interface

Access to the admin interface is limited to studio staff. This interface allows users to manage the showcase site parameters, as well as artist planning and bookings. The features are divided into three main categories: site management, studio management, and personal management.

- **Personal Management Features**:
  - **Admin Dashboard**: Interface for managing incoming forms, appointments, and payments.
  - **My Clients**: Interface for managing client information.
  - **My Bookings**: Interface for managing personal bookings.

- **Studio Management Features**:
  - **Team**: Interface for managing team members.
  - **KPI**: Interface for viewing key performance indicators.
  - **Finances**: Interface for managing financial information.

- **Site Management Features**:
  - **Site Artists**: Interface for managing artist profiles on the site.
  - **Site Gallery**: Interface for managing the site's gallery.
  - **Site Parameters**: Interface for managing site settings.

    - **Appointment Booking**: System for clients to book appointment slots online.
    - **Online Payments**: Secure online payment system for booking and services.

### Database

- **Tables/Collections** :
    - **Users** : Informations sur les utilisateurs (clients et artistes).
    - **Artists** : Profils et portfolios des artistes.
    - **Tattoos** : Informations et images des tatouages.
    - **Appointments** : Informations sur les rendez-vous (dates, heures, clients).
    studio

## Workflow

Clients visit the showcase site, complete the booking form, and submit it. The admin interface then receives the form, and an artist reviews the request. The artist may contact the client to discuss their project, provide pricing, and confirm availability. If the client agrees, the artist can book a slot directly in the in-app calendar.

## Usage

client go to showcase site, complete the form and click the button submit.
then the admin interface will receive the form and the artist will check the demand, potentially
contact the client to discuss their project, give them their price and availabilities.
it the client agrees, the artist can directly book a slot in its in app calendar.

### Admin Panel

1. **Login**: Navigate to `http://127.0.0.1:5000/admin` and log in with your admin credentials.
2. **Manage Content**: Use the admin panel to manage website content, view appointments, and handle payments.

### Booking an Appointment

1. **Navigate to the Booking Page**: Go to the appointment booking page on the website.
2. **Select a Slot**: Choose an available time slot and fill in your details.
3. **Make a Payment**: Complete the booking by making an online payment.

## Contact

For any questions or inquiries, please contact me at:

- **Email**: emeline_bgs@hotmail.com
- **Name**: Emeline BAGORIS
- **Github username**: easartem
- **EdX username**: emeline_bgs
- **Location**: Paris, France
