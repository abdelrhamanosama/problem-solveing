-- Last updated: 6/10/2026, 11:48:43 AM
# Write your MySQL query statement below
select 
    e1.name as name
from 
    Employee  as e1
join
    Employee as e2
on 
    e1.id = e2.managerId
group by
    e1.id
having 
    count(e1.id) >= 5;

    