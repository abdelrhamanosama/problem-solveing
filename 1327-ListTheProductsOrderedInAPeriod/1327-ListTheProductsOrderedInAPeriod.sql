-- Last updated: 9/6/2026, 2:26:35 PM
# Write your MySQL query statement below
with compactProducts as(
    select product_id , sum(unit) as unit
    from Orders
    where order_date between '2020-02-01'and '2020-02-29'
    group by product_id
)

select product_name ,unit
from compactProducts
join Products 
on Products.product_id = compactProducts.product_id and unit >= 100;