-- Last updated: 6/10/2026, 11:44:37 AM
# Write your MySQL query statement below

SELECT
employee_id, department_id
FROM Employee 
WHERE primary_flag = 'Y'
#GROUP BY employee_id
#HAVING count(department_id) > 1

UNION ALL

SELECT
employee_id, department_id
FROM Employee 
GROUP BY employee_id
HAVING count(department_id) = 1