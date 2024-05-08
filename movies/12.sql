

SELECT title FROM movies WHERE id IN
    (SELECT movie_id FROM stars WHERE person_id IN
        (SELECT id FROM people WHERE name = 'Bradley Cooper' OR name = 'Jennifer Lawrence'));

SELECT m.id, s.movie_id, s.person_id
FROM movies AS m, stars AS s
WHERE m.id=s.movie_id AND s.person_id
