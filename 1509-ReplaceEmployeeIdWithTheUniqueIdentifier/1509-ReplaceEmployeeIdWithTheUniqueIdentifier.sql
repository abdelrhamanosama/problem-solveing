-- Last updated: 6/10/2026, 11:46:09 AM
# Write your MySQL query statement below
select name , unique_id 
from Employees e
left join EmployeeUNI eu 
on e.id = eu.id;