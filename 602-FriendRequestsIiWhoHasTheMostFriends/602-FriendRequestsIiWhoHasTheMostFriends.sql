-- Last updated: 9/6/2026, 4:02:18 PM
with Friends as (
    select 
        accepter_id as id
    from
       RequestAccepted 
    union all
    select 
        requester_id as id
    from 
        RequestAccepted 
)

select 
    id , 
    count(id) as num
from 
    Friends
group by 
    id
order by 
    num desc
limit 1;