SELECT name FROM stars JOIN people ON stars.person_id = people.id
WHERE id =(SELECT id FROM movies WHERE title = 'Toy Story');

