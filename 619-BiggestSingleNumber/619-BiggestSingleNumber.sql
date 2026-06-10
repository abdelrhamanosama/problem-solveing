-- Last updated: 6/10/2026, 11:48:31 AM
# Write your MySQL query statement below
select max(num)  as num
from (select num 
from MyNumbers
group by num
having count(num) = 1) as t
;