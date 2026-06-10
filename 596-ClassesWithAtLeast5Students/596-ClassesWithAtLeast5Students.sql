-- Last updated: 6/10/2026, 11:48:34 AM
# Write your MySQL query statement below
select class
from Courses
group by class
having count(class) >= 5