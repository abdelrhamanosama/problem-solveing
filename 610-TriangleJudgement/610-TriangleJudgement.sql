-- Last updated: 6/10/2026, 11:48:32 AM
# Write your MySQL query statement below
select x,y,z , 
case when x+y > z and z+x  > y and y+z > x then "Yes" else "No" end  as triangle
from Triangle