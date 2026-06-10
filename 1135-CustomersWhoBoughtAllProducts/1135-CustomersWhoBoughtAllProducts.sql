-- Last updated: 6/10/2026, 11:47:19 AM
# Write your MySQL query statement below
select customer_id
from Customer 
group by customer_id  
having count(distinct product_key ) =  (select count(*) as total from Product);