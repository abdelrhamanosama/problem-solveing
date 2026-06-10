-- Last updated: 6/10/2026, 11:45:30 AM
# Write your MySQL query statement below
select customer_id , count(customer_id) as count_no_trans
from Visits v
left join Transactions t
on v.visit_id = t.visit_id
where t.visit_id is null
group by customer_id;