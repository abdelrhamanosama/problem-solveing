-- Last updated: 6/10/2026, 11:47:16 AM
# Write your MySQL query statement below
select s.product_id, s.year as first_year ,  s.quantity ,  s.price
from Sales as s , (
    select product_id , min(year) as mny from Sales group by product_id
)as t
where s.product_id = t.product_id and t.mny = s.year;