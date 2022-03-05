SELECT name FROM people JOIN stars ON
person_id = people.id WHERE movie_id =
(SELECT id FROM movies WHERE title LIKE '%Toy Story%');
