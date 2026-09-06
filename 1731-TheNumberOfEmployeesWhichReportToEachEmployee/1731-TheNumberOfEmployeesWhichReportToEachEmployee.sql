-- Last updated: 9/6/2026, 2:21:31 PM
# Write your MySQL query statement below
select 
    e1.employee_id , e1.name  , count((e2.reports_to))as reports_count , round(avg(e2.age))as           average_Age 
from    
    Employees e1  
join    
    Employees e2
on
   e1.employee_id = e2.reports_to
group by  
    employee_id
order by
    employee_id 
