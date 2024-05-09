---------------------------------------------LAUNCHING THE INVESTIGATION-----------------------------------------------------

-- The only information we have to start is that the theft took place on July 28, 2023 on Humphrey Street.


-- Since we have a database at our disposition to investigate, the first thing to do is to take a look at its global organisation.
.table
.schema
-- Using the keyword table, we found 10 tables their columns description with the keyword schema :
    -- airports(id, abbreviation, full_name, city)
    -- atm_transactions(id, account_number, year, month, day, atm_location, transaction_type, amount)
    -- bakery_security_logs(#id, year, month, day, hour, minute, activity, license_plate)
    -- bank_accounts(account_number, person_id, creation_year) person_id ref people(id)
    -- crime_scene_reports(#id, year, month, day, street, description)
    -- flights(id, origin_airport, destination_airport, year, month, day, hour, minute, origin_airport_id, destination_airport_id)
    -- interviews(id, name, year, month, day, transcript)
    -- passengers(flight_id, passport_number, seat)
    -- people(id, name, phone_number, passport_number, license_plate)
    -- phone_calls(id, caller, receiver, year, month, day, duration)


-- To get started on this case, We can search through the crime_scene_reports table with our initial information (date and street).
SELECT *
  FROM crime_scene_reports
 WHERE year = '2023' AND month = '7' AND day = '28'
   AND street = 'Humphrey Street';

-- New information unlocked !
    -- The exact hour of the crime is 10:15am.
    -- The exact location is the bakery of Humphrey Street.
    -- There is three interviews made by three witnesses.


---------------------------------------------READING THE WITNESSES INTERVIEW-------------------------------------------------

-- Let's go look at the transcript from the witnesses in the table interviews !
-- But we don't have the name of the three witnesses and the table interviews records transcript with name and date/time.
-- Since the query won't be precise, let's check the total number of transcripts existing for our date and time.
SELECT COUNT(*)
  FROM interviews
 WHERE year = '2023' AND month = '7' AND day = '28';


-- There is 7 interviews but we are only interested by 3, let's read them to find the 3 we want !
SELECT name, transcript
  FROM interviews
 WHERE year = '2023' AND month = '7' AND day = '28';
-- New information unlocked !
    -- The three witnesses are Ruth, Eugene and Raymond. Each of them gave us a new lead on the mystery:
        -- Ruth lead : check the security footage of the bakery parking lot. The thief left by car within 10 min after crime began (10:15am -> 10:25am).
        -- Eugene lead : check the atm transactions on the morning of crime. The thief withdrawed money at the ATM of Leggett Street in the morning.
        -- Raymond lead :
            -- check the phone_calls. The thief called someone less than 1 min between 10:15am and 10:25am.
            -- check the flights and bank_accounts. He asked his collaborator to book him the earliest flight out of town tomorrow (29 july 2023).


---------------------------------------------RUTH LEAD-----------------------------------------------------------------------

-- We look for the car's license plate in the timeframe given by Ruth from the table bakery_security_logs.
SELECT COUNT(*)
  FROM bakery_security_logs
 WHERE year = '2023' AND month = '7' AND day = '28' AND hour = '10'
   AND (minute >= 15 AND minute <= 25);


-- 8 people left during that timeframe, later we can cross the 8 license pates given by this query with the table people to get the 8 suspect's name.
SELECT activity, license_plate
  FROM bakery_security_logs
 WHERE year = '2023' AND month = '7' AND day = '28' AND hour = '10'
   AND (minute >= 15 AND minute <= 25);


-- New information unlocked !
    -- There is 8 suspects for this case (8 license plates).
    -- Each suspect can be identified with it's car's license plate in the table people.


---------------------------------------------EUGENE LEAD---------------------------------------------------------------------

-- Eugene told us that he saw the suspect at the atm of Leggett Street withdrawing money on the morning of the crime.
SELECT account_number, amount
  FROM atm_transactions
 WHERE year = '2023' AND month = '7' AND day = '28'
   AND atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw';


-- New information unlocked !
    -- There is 8 suspects people corresponding to the specifications given by Eugene (8 account number).
    -- Each suspect can be identified with it's account number in the table people.


---------------------------------------------RAYMOND LEAD--------------------------------------------------------------------

-- Check the phone_calls table. The thief called someone less than 1 min between 10:15am and 10:25am.
SELECT COUNT(*)
  FROM phone_calls
 WHERE year = '2023' AND month = '7' AND day = '28'
   AND duration <= '60';
--> 10 calls were made of a duration < 60 seconds during our timeframe.


-- Check the flights. He asked his collaborator to book him the earliest flight out of town tomorrow (29 july 2023).
SELECT * FROM flights WHERE year = '2023' AND month = '7' AND day = '29';
--> 5 flights at this date with same origin_airport_id (8) but different destination_airport_id.

-- Just to be sure, we should check that all flights departs from the airport of get id of the airport of Fiftyville.
SELECT id FROM airports WHERE city = 'Fiftyville';
--> It is indeed 8.

-- Now, we get the flight he took and the destination_airport_id
SELECT id, destination_airport_id FROM flights WHERE year = '2023' AND month = '7' AND day = '29' AND origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') ORDER BY hour ASC, minute ASC LIMIT 1;
-- find which is the destination : New York City LaGuardia Airport LGA
SELECT * FROM airports WHERE id = '4';

-- .schema passengers(flight_id, passport_number, seat)
SELECT passport_number FROM passengers WHERE flight_id = '36';
-- 8 passport for 8 people


---------------------------------------------CROSSING THE DATA : FIND THE CITY---------------------------------------------------------------


-- .schema people(id, name, phone_number, passport_number, license_plate)
SELECT license_plate FROM bakery_security_logs WHERE year = '2023' AND month = '7' AND day = '28' AND hour = '10' AND (minute >= 15 AND minute <= 25);

SELECT * FROM people WHERE license_plate IN
    (SELECT license_plate FROM bakery_security_logs WHERE year = '2023' AND month = '7' AND day = '28' AND hour = '10' AND (minute >= 15 AND minute <= 25));


SELECT * FROM phone_calls WHERE year = '2023' AND month = '7' AND day = '28' AND duration <= '60';


---------------------------------------------CROSSING THE DATA : FIND THE CULPRIT------------------------------------------------------------


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


SELECT * FROM people WHERE id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN
        (SELECT account_number FROM atm_transactions WHERE year = '2023' AND month = '7' AND day = '28' AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'));


---------------------------------------------CROSSING THE DATA : FIND THE ACCOMPLICE---------------------------------------------------------

SELECT * FROM people WHERE phone_number IN
    (SELECT receiver FROM phone_calls WHERE year = '2023' AND month = '7' AND day = '28' AND duration <= '60' AND caller = (SELECT phone_number FROM people WHERE id = '686048'));

