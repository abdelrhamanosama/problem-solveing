-- Last updated: 9/6/2026, 2:21:37 PM
# Write your MySQL query statement below
select user_id , count(user_id) as followers_count
from Followers
group by user_id
order by user_id asc;