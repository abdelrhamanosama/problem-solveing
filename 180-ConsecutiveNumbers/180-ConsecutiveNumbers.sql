-- Last updated: 6/10/2026, 11:50:03 AM
# Write your MySQL query statement below
select  distinct (l1.num)as  ConsecutiveNums
from logs l1, logs l2 , logs l3
where l1.num = l2.num and l1.num = l3.num and abs(l1.id - l2.id) = 1 and abs(l2.id - l3.id) = 1 and abs(l1.id-l3.id)= 2;