-- Last updated: 9/6/2026, 4:04:49 PM
WITH RankedSalaries AS (
    SELECT
        salary,
        DENSE_RANK() OVER (
            ORDER BY salary DESC
        ) AS salary_rank
    FROM (
        SELECT DISTINCT salary
        FROM Employee
    ) AS salaries
)

SELECT
    (
        SELECT salary
        FROM RankedSalaries
        WHERE salary_rank = 2
    ) AS SecondHighestSalary;