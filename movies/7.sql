SELECT title, rating FROM movies ORDER BY title ASC JOIN ratings ON movies.id = ratings.movie_id WHERE year = '2010' ORDER BY rating DESC;
