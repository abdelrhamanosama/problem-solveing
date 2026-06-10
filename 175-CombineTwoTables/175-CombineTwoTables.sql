-- Last updated: 6/10/2026, 11:50:04 AM
# Write your MySQL query statement below
select firstName ,
        lastName ,
        city ,
        state
from 
    Person p
left join 
    Address a
on 
    p.personId = a.personId
