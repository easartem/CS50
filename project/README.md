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

### Architecture
Features
Homepage: A welcoming page with information about the studio.
About: Detailed information about the studio and its artists.
Services: Information on the various tattoo services offered.
Portfolio: Gallery showcasing previous tattoo work.
Blog/News: Updates and news related to the studio.
Contact: Contact form for inquiries.
Admin Panel: Interface for managing the website content, appointments, and payments.
Appointment Booking: System for clients to book appointment slots online.
Online Payments: Secure online payment system for booking and services.
Additional Functionalities
Système de Réservation de Créneaux

Frontend: Interfaces for clients to view and book available slots.
Backend: Software to manage bookings, cancellations, and notifications.
Admin Interface: Tools for admins to manage slots, view bookings, and modify schedules.
Système de Paiement en Ligne

Integration with payment gateways such as Stripe or PayPal.
Backend: System to process payments, manage refunds, and generate receipts/invoices.
Security: Implementation of security measures to protect client payment information.
This architecture provides a comprehensive structure for the website, ensuring both user-facing and administrative functionalities are well-integrated.

1. Global structure

2. The showcase website

3. The admin interface
- **Homepage**: A welcoming page with information about the studio.
- **About**: Detailed information about the studio and its artists.
- **Services**: Information on the various tattoo services offered.
- **Portfolio**: Gallery showcasing previous tattoo work.
- **Blog/News**: Updates and news related to the studio.
- **Contact**: Contact form for inquiries.
- **Admin Panel**: Interface for managing the website content, appointments, and payments.
- **Appointment Booking**: System for clients to book appointment slots online.
- **Online Payments**: Secure online payment system for booking and services.



### The showcase website

### The admin interface

### **Base de Données :**

- **Tables/Collections** :
    - **Users** : Informations sur les utilisateurs (clients et artistes).
    - **Artists** : Profils et portfolios des artistes.
    - **Tattoos** : Informations et images des tatouages.
    - **Appointments** : Informations sur les rendez-vous (dates, heures, clients).

## Usage

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
