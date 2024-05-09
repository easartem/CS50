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
-- 8 people left during that timeframe, we can cross the table to get a list of 8 names of people having the license plate in the table people
SELECT activity, license_plate FROM bakery_security_logs WHERE year = '2023' AND month = '7' AND day = '28' AND hour = '10' AND (minute >= 15 AND minute <= 25);


-- .schema atm_transactions(id, account_number, year, month, day, atm_location, transaction_type, amount)
-- we
SELECT account_number, transaction_type, amount FROM atm_transactions WHERE year = '2023' AND month = '7' AND day = '28' AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
-- 8 withdraw and 1 deposit were made
-- .schema bank_accounts(account_number, person_id, creation_year) person_id ref people(id)
-- there is no hour indication in those 2 tables but we can cross the table to get a list of 9 names of people having used the atm


-- .schema people(id, name, phone_number, passport_number, license_plate)
-- .schema phone_calls (id, caller, receiver, year, month, day, duration)
SELECT * FROM phone_calls WHERE year = '2023' AND month = '7' AND day = '28' AND duration <= '60';

-- .schema flights(id, origin_airport, destination_airport, year, month, day, hour, minute, origin_airport_id, destination_airport_id)
SELECT * FROM flights WHERE year = '2023' AND month = '7' AND day = '29';

-- .schema airports(id, abbreviation, full_name, city)
-- get id of the airport of Fiftyville
SELECT id FROM airports WHERE city = 'Fiftyville';
-- get the flight he took and the destination_airport_id
SELECT id, destination_airport_id FROM flights WHERE year = '2023' AND month = '7' AND day = '29' AND origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') ORDER BY hour ASC, minute ASC LIMIT 1;
-- find which is the destination : New York City LaGuardia Airport LGA
SELECT * FROM airports WHERE id = '4';

-- .schema passengers(flight_id, passport_number, seat)
SELECT passport_number FROM passengers WHERE flight_id = '36';
-- 8 passport for 8 people




-- .schema people(id, name, phone_number, passport_number, license_plate)
SELECT license_plate FROM bakery_security_logs WHERE year = '2023' AND month = '7' AND day = '28' AND hour = '10' AND (minute >= 15 AND minute <= 25);

SELECT * FROM people WHERE license_plate IN
    (SELECT license_plate FROM bakery_security_logs WHERE year = '2023' AND month = '7' AND day = '28' AND hour = '10' AND (minute >= 15 AND minute <= 25));




SELECT * FROM phone_calls WHERE year = '2023' AND month = '7' AND day = '28' AND duration <= '60';



SELECT * FROM people WHERE phone_number IN
    (SELECT caller FROM phone_calls WHERE year = '2023' AND month = '7' AND day = '28' AND duration <= '60')
INTERSECT
SELECT * FROM people WHERE license_plate IN
    (SELECT license_plate FROM bakery_security_logs WHERE year = '2023' AND month = '7' AND day = '28' AND hour = '10' AND (minute >= 15 AND minute <= 25))
INTERSECT
SELECT * FROM people WHERE passport_number IN
    (SELECT passport_number FROM passengers WHERE flight_id = '36')
INTERSECT
SELECT * FROM people WHERE id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN
        (SELECT account_number FROM atm_transactions WHERE year = '2023' AND month = '7' AND day = '28' AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'));

-- .schema atm_transactions(id, account_number, year, month, day, atm_location, transaction_type, amount)
SELECT * FROM people WHERE id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN
        (SELECT account_number FROM atm_transactions WHERE year = '2023' AND month = '7' AND day = '28' AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'));
-- .schema bank_accounts(account_number, person_id, creation_year) person_id ref people(id)


SELECT * FROM people WHERE phone_number IN
    (SELECT caller FROM phone_calls WHERE year = '2023' AND month = '7' AND day = '28' AND duration <= '60');

SELECT * FROM phone_calls WHERE year = '2023' AND month = '7' AND day = '28' AND duration <= '60';
