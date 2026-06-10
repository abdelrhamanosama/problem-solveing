-- Last updated: 6/10/2026, 11:48:40 AM
# Write your MySQL query statement below
select
    name
from
    Customer
where 
    referee_id is null or referee_id <> 2;