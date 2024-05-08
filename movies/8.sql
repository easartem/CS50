SELECT name FROM people
SELECT person_id FROM stars WHERE id =(SELECT id FROM movies WHERE title = 'Toy Story');

