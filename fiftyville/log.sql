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
-- New information unlocked ! hour of crime 10:15am at the bakery + existence if three interviews by witnesses

-- let's go look at the transcript from the witnesses in the interviews table
.schema interviews
-- interviews(id, name, year, month, day, transcript)
-- There is 7 interviews but we are only interested by 3
SELECT COUNT(*) FROM interviews WHERE year = '2023' AND month = '7' AND day = '28';
-- Let's read them to find the 3 we want (Ruth, Eugene and Raymond)
SELECT name, transcript FROM interviews WHERE year = '2023' AND month = '7' AND day = '28';
-- New information unlocked !
-------- Ruth : check the security footage of the bakery parking lot. The thief left by car within 10 min after crime began (10:15am -> 10:25am)
-------- Eugene : check the atm transactions ot the morning of crime. The thief withdrawed money at the ATM of Leggett Street in the morning.
-------- Raymond : check the phone_calls, flights and bank_accounts. The thief called someone less than 1 min between 10:15am and 10:25am.
-------- Raymond : check the flights and bank_accounts. He asked his collaborator to book him the earliest flight out of town tomorrow (29 july 2023)

-- .schema bakery_security_logs(#id, year, month, day, hour, minute, activity, license_plate)
-- we look for the car's license plate in the timeframe given by Ruth
SELECT COUNT(*) FROM bakery_security_logs WHERE year = '2023' AND month = '7' AND day = '28' AND hour = '10' AND (minute >= 15 AND minute <= 25);
-- 8 people left during that timeframe
SELECT activity, license_plate FROM bakery_security_logs WHERE year = '2023' AND month = '7' AND day = '28' AND hour = '10' AND (minute >= 15 AND minute <= 25);


-- .schema atm_transactions(id, account_number, year, month, day, atm_location, transaction_type, amount)
-- we
SELECT account_number, transaction_type, amount FROM atm_transactions WHERE year = '2023' AND month = '7' AND day = '28' AND atm_location = 'Leggett Street';
-- 1 withdraw and 8 deposit were made 
