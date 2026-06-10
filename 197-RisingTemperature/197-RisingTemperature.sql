-- Last updated: 6/10/2026, 11:49:56 AM
# Write your MySQL query statement below
/*
select id
from Weather w
where exists ( select * from Weather w2 where DATEDIFF(w.recordDate, w2.recordDate) = 1
  and w.temperature > w2.temperature);*/
select 
    w.id 
from 
    Weather w
join 
    Weather w2
on 
    DATEDIFF(w.recordDate, w2.recordDate) = 1  
where 
    w.temperature > w2.temperature ;
    