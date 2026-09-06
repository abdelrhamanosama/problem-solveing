-- Last updated: 9/6/2026, 2:25:12 PM
# Write your MySQL query statement below
select name , unique_id 
from Employees e
left join EmployeeUNI eu 
on e.id = eu.id;