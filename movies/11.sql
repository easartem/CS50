SELECT title FROM movies WHERE id IN
    (SELECT movie_id FROM stars WHERE person_in =
        (SELECT id FROM people WHERE name = 'Chadwick Boseman'))
            ORDER BY 

