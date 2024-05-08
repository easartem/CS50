-- Keep a log of any SQL queries you execute as you solve the mystery.

-- The theft took place on July 28, 2023 and that it took place on Humphrey Street.

-- Get an idea of the organisation of the database
-- airports, atm_transactions, bakery_security_logs, bank_accounts, crime_scene_reports
-- flights, interviews, passengers, people, phone_calls
.table

-- crime_scene_reports(#id, year, month, day, street, description)
.schema crime_scene_reports

SELECT * FROM crime_scene_reports WHERE year = '2023' AND month = 'July' AND day = '28';
