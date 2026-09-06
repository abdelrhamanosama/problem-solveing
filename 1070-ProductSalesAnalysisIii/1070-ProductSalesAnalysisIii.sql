-- Last updated: 9/6/2026, 4:00:04 PM
# Write your MySQL query statement below
select s.product_id, s.year as first_year ,  s.quantity ,  s.price
from Sales as s , (
    select product_id , min(year) as mny from Sales group by product_id
)as t
where s.product_id = t.product_id and t.mny = s.year;