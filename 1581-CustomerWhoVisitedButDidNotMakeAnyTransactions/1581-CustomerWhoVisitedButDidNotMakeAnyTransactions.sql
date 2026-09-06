-- Last updated: 9/6/2026, 2:22:30 PM
# Write your MySQL query statement below
select customer_id , count(customer_id) as count_no_trans
from Visits v
left join Transactions t
on v.visit_id = t.visit_id
where t.visit_id is null
group by customer_id;