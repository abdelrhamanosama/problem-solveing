-- Last updated: 6/10/2026, 11:45:22 AM
-- # Write your MySQL query statement below
select
    r.contest_id , 
    round(ifnull((count(r.contest_id)*1.0/z.y
        
    ),0)*100,2)   as percentage 
from 
    Register r , (select count(*) as y from (select count(user_id) as x from Users group by user_id)as k group by k.x) z
group by
    r.contest_id
order by 
    percentage desc ,contest_id  asc ;
-- select count(*) as y from (select count(user_id) as x from Users group by user_id)as k group by k.x;