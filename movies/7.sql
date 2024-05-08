SELECT AVG(rating) FROM ratings WHERE movie_id IN
SELECT title FROM movies WHERE year = '2010';
