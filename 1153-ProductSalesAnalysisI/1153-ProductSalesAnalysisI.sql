-- Last updated: 6/10/2026, 11:47:18 AM
# Write your MySQL query statement below
select product_name , year , price
from Sales s
join Product p
on s.product_id = p.product_id;