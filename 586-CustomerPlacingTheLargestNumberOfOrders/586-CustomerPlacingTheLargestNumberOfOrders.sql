-- Last updated: 6/10/2026, 11:48:39 AM
select customer_number
from Orders
group by customer_number
order by count(customer_number) desc
limit 1;