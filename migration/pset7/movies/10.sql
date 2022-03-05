SELECT name FROM people JOIN directors ON
person_id = people.id WHERE movie_id IN
(SELECT id FROM movies JOIN ratings ON
ratings.movie_id = movies.id WHERE rating >= 9.0);
