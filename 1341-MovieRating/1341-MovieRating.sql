-- Last updated: 9/6/2026, 2:26:14 PM
WITH 
cte AS (
    SELECT movie_id, AVG(rating) AS avg_rating
    FROM MovieRating 
    WHERE created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY movie_id
),
ctee AS (
    SELECT user_id, COUNT(user_id) AS count_user
    FROM MovieRating   
    GROUP BY user_id
),
ctB AS (
    SELECT title AS results
    FROM Movies
    JOIN cte ON cte.movie_id = Movies.movie_id
    ORDER BY cte.avg_rating DESC, title ASC
    LIMIT 1
),
ctA AS (
    SELECT name AS results
    FROM Users
    JOIN ctee ON ctee.user_id = Users.user_id
    ORDER BY ctee.count_user desc,name ASC
    LIMIT 1
)
SELECT * FROM ctA
UNION all 
SELECT * FROM ctB