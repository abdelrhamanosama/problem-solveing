-- Last updated: 9/6/2026, 4:00:07 PM
# Write your MySQL query statement below
select product_name , year , price
from Sales s
join Product p
on s.product_id = p.product_id;