-- Last updated: 9/6/2026, 4:04:42 PM
# Write your MySQL query statement below
with rankingEmployee as (
    select 
        id ,
        name ,
        salary ,
        departmentId,
        dense_rank()over(
            partition by departmentId
            order by salary desc
        ) as drnk
    from 
        Employee
    
)

select 
    -- RE.drnk,
    D.name as Department,
    RE.name as Employee,
    RE.salary as salary
from   
    rankingEmployee as RE
join 
    Department D
on 
    D.id = RE.departmentId
where  
    RE.drnk < 4

