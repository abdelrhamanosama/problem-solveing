-- Last updated: 9/6/2026, 2:21:57 PM
# Write your MySQL query statement below
select 
    user_id,
    concat(substring(upper(name),1,1),substring(lower(name),2)) as name
from 
    Users
order  by user_id asc