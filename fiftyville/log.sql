-- Keep a log of any SQL queries you execute as you solve the mystery.

-- The theft took place on July 28, 2023 and that it took place on Humphrey Street.

-- Get an idea of the organisation of the database
-- airports, atm_transactions, bakery_security_logs, bank_accounts, crime_scene_reports
-- flights, interviews, passengers, people, phone_calls
.table

-- crime_scene_reports(#id, year, month, day, street, description)
.schema crime_scene_reports

-- start from the crime scene report with the initial information (date and street)
SELECT * FROM crime_scene_reports WHERE year = '2023' AND month = '7' AND day = '28' AND street = 'Humphrey Street';
-- new information unlocked ! hour of crime 10:15am at the bakery + existence if three interviews by witnesses

-- let's go look at the transcript from the witnesses in the interviews table
.schema interviews
-- interviews(id, name, year, month, day, transcript)
-- There is 7 interviews but we are only interested by 3
SELECT COUNT(*) FROM interviews WHERE year = '2023' AND month = '7' AND day = '28';

SELECT name, transcript FROM interviews WHERE year = '2023' AND month = '7' AND day = '28';

