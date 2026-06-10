-- Last updated: 6/10/2026, 11:48:29 AM
# Write your MySQL query statement below
select 
    id,
    movie,
    description,
    rating
from 
    Cinema
where 
    id%2 = 1 and  description <> "boring"
order by
    rating desc
;