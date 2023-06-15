-- Keep a log of any SQL queries you execute as you solve the mystery.
tables:
.tables
airports              crime_scene_reports   people
atm_transactions      flights               phone_calls
bakery_security_logs  interviews
bank_accounts         passengers

.schema crime_scene_reports
CREATE TABLE crime_scene_reports (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    street TEXT,
    description TEXT,
    PRIMARY KEY(id)



--1. Start by pulling the crime report for time/place of the theft
SELECT id, description FROM crime_scene_reports WHERE street = "Humphrey Street" AND day = 28 AND month = 07 AND year = 2021;
--theft of the Duck occurred at 10:15 am @ Humphrey Street Bakery; 3 eyewitnesses corroborating interview transcripts.
--littering @ 16:36, no witnesses. (irrelevant info? tbd)

--2. Pull 3 eyewitness interview reports from TABLE interviews to get names and transcripts
--.schema interviews
--CREATE TABLE interviews (
    id INTEGER,
    name TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    transcript TEXT,
    PRIMARY KEY(id)
SELECT name, transcript FROM interviews WHERE day = 28 AND month = 07 AND year = 2021;
--7 witness statements returned (results/output).
--Of those, 3 mention the theft: Eugene, Raymond, Ruth
--Bonus info: Emma is owner of bakery; was seen whispering into a phone for approx. 30m; never purchased anything.
--##Eugene: it's someone he recognized but not by name. Saw the thief using the ATM on Leggett St
--##Raymond: As thief left bakery, Ray overheard plan to take earliest flight out of Fiftyville. call lasted <1m;
    --Thief asked person on the other end of the phone to purchase plane ticket.
--##Ruth: within 10m of the theft, the thief got into a car in the bakery parking lot.

--3. get license plate # and owner name (on July 28, 2021, bakery parking lot, between 10:15 and 10:25 am)
SELECT name, phone_number, passport_number, license_plate FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 07 AND year = 2021 AND hour = 10 AND minute >=15 AND minute <=25 AND activity = "exit");
+---------+----------------+-----------------+---------------+
|  name   |  phone_number  | passport_number | license_plate |
+---------+----------------+-----------------+---------------+
| Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
| Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
| Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
| Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
| Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
| Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
| Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
| Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
+---------+----------------+-----------------+---------------+

--4. find bank account details via ATM transactions
--thanks to a possible caller//before noon//withdrawals//on Leggett Street

SELECT name, passport_number, bank_accounts.account_number FROM people, atm_transactions, bank_accounts WHERE people.id = bank_accounts.person_id AND atm_transactions.account_number = bank_accounts.account_number AND day = 28 AND month = 07 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

+---------+-----------------+----------------+
|  name   | passport_number | account_number |
+---------+-----------------+----------------+
| Bruce   | 5773159633      | 49610011       |
| Diana   | 3592750733      | 26013199       |
| Brooke  | 4408372428      | 16153065       |
| Kenny   | 9878712108      | 28296815       |
| Iman    | 7049073643      | 25506511       |
| Luca    | 8496433585      | 28500762       |
| Taylor  | 1988161715      | 76054385       |
| Benista | 9586786673      | 81061156       |
+---------+-----------------+----------------+

--8 results - 3 repeats who appeared in a previous query (#3.)
--Bruce, Iman, & Luca all match this.

--5. find both caller and recipient of the call at the bakery Raymond mentioned
    --to refresh:
    --<1min in duration
    --caller asked receiver to purchase flight
    --I tried SELECT caller, receiver, duration FROM phone_calls to first see what the data looks like
SELECT caller, name FROM phone_calls, people WHERE people.phone_number = receiver AND day = 28 AND month = 7 AND year = 2021 AND duration < 60 ORDER BY phone_calls.id;
+----------------+------------+
|     caller     |    name    |
+----------------+------------+
| (130) 555-0289 | Jack       |
| (499) 555-9472 | Larry      |
| (367) 555-5533 | Robin      |
| (499) 555-9472 | Melissa    |
| (286) 555-6063 | James      |
| (770) 555-1861 | Philip     |
| (031) 555-6622 | Jacqueline |
| (826) 555-1652 | Doris      |
| (338) 555-6650 | Anna       |
+----------------+------------+
--9 matching calls; Bruce was the ONLY caller who used the ATM from the previous query.

SELECT receiver, name FROM phone_calls, people WHERE people.phone_number = receiver AND day = 28 AND month = 7 AND year = 2021 AND duration < 60 ORDER BY phone_calls.id;
+----------------+------------+
|    receiver    |    name    |
+----------------+------------+
| (996) 555-8899 | Jack       |
| (892) 555-8872 | Larry      |
| (375) 555-8161 | Robin      |
| (717) 555-1342 | Melissa    |
| (676) 555-6554 | James      |
| (725) 555-3243 | Philip     |
| (910) 555-3251 | Jacqueline |
| (066) 555-9701 | Doris      |
| (704) 555-2131 | Anna       |
+----------------+------------+
--Robin was the person on the phone with Bruce, who is the person who bought the ticket

--6.    check the flight departing Fiftyville next morning (July 29, 2021)
    --find out destination
    --passengers' details
SELECT airports.city, airports.full_name, people.name, people.passport_number FROM airports, flights, passengers, people WHERE airports.id = flights.destination_airport_id AND flights.id = passengers.flight_id AND passengers.passport_number = people.passport_number AND flights.origin_airport_id = (SELECT airports.id FROM airports WHERE city = "Fiftyville") AND day = 29 AND month = 7 AND year = 2021 ORDER BY flights.hour;
+---------------+-------------------------------------+-----------+-----------------+
|     city      |              full_name              |   name    | passport_number |
+---------------+-------------------------------------+-----------+-----------------+
| New York City | LaGuardia Airport                   | Doris     | 7214083635      |
| New York City | LaGuardia Airport                   | Sofia     | 1695452385      |
| New York City | LaGuardia Airport                   | Bruce     | 5773159633      |
| New York City | LaGuardia Airport                   | Edward    | 1540955065      |
| New York City | LaGuardia Airport                   | Kelsey    | 8294398571      |
| New York City | LaGuardia Airport                   | Taylor    | 1988161715      |
| New York City | LaGuardia Airport                   | Kenny     | 9878712108      |
| New York City | LaGuardia Airport                   | Luca      | 8496433585      |
| Chicago       | O'Hare International Airport        | Daniel    | 7597790505      |
| Chicago       | O'Hare International Airport        | Carol     | 6128131458      |
| Chicago       | O'Hare International Airport        | Rebecca   | 6264773605      |
| Chicago       | O'Hare International Airport        | Sophia    | 3642612721      |
| Chicago       | O'Hare International Airport        | Heather   | 4356447308      |
| Chicago       | O'Hare International Airport        | Marilyn   | 7441135547      |
| San Francisco | San Francisco International Airport | Dennis    | 4149859587      |
| San Francisco | San Francisco International Airport | Jose      | 9183348466      |
| San Francisco | San Francisco International Airport | Jennifer  | 7378796210      |
| San Francisco | San Francisco International Airport | Brandon   | 7874488539      |
| San Francisco | San Francisco International Airport | Matthew   | 4195341387      |
| San Francisco | San Francisco International Airport | Emily     | 6263461050      |
| San Francisco | San Francisco International Airport | Douglas   | 3231999695      |
| San Francisco | San Francisco International Airport | Jordan    | 7951366683      |
| Tokyo         | Tokyo International Airport         | Richard   | 7894166154      |
| Tokyo         | Tokyo International Airport         | Thomas    | 6034823042      |
| Tokyo         | Tokyo International Airport         | Brooke    | 4408372428      |
| Tokyo         | Tokyo International Airport         | Larry     | 2312901747      |
| Tokyo         | Tokyo International Airport         | Steven    | 1151340634      |
| Tokyo         | Tokyo International Airport         | John      | 8174538026      |
| Tokyo         | Tokyo International Airport         | Pamela    | 1050247273      |
| Tokyo         | Tokyo International Airport         | Melissa   | 7834357192      |
| Boston        | Logan International Airport         | Gloria    | 2835165196      |
| Boston        | Logan International Airport         | Kristina  | 6131360461      |
| Boston        | Logan International Airport         | Douglas   | 3231999695      |
| Boston        | Logan International Airport         | Diana     | 3592750733      |
| Boston        | Logan International Airport         | Christian | 2626335085      |
| Boston        | Logan International Airport         | Michael   | 6117294637      |
| Boston        | Logan International Airport         | Ethan     | 2996517496      |
| Boston        | Logan International Airport         | Charles   | 3915621712      |
+---------------+-------------------------------------+-----------+-----------------+
--Bruce is on the passenger list; destination airport NYC
--it's the same Bruce as Query#3 because of matching passport numbers!