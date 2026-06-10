-- Last updated: 6/10/2026, 11:50:00 AM
# Write your MySQL query statement below
select email 
from Person
group by email
having count(email) > 1