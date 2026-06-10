-- Last updated: 6/10/2026, 11:47:13 AM
# Write your MySQL query statement below
select 
    round(sum(
        case when d.player_id = t.player_id and  datediff(d.event_date , t.mnd) = 1 then 1 else 0 end
    )*1.0/count( distinct d.player_id  ),2)
    as fraction   
from 
    Activity as d , (
select
    player_id  ,
    min(event_date)  as mnd
from 
    Activity  
group by player_id  )as t 

