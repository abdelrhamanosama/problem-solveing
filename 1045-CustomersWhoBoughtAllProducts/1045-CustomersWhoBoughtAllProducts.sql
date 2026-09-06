-- Last updated: 9/6/2026, 4:00:09 PM
with countingCustomersWithProducts as(
select
    customer_id, 
    count(distinct product_key) as num_prod
from
    Customer

group by 
    customer_id
)

select 
    customer_id
from
    countingCustomersWithProducts
where 
    num_prod = (select count(distinct product_key)  from Product)