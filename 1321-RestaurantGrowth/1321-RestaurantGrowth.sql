-- Last updated: 9/6/2026, 2:26:54 PM
WITH daily_sales AS (
    SELECT
        visited_on,
        SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
)

SELECT
    current_day.visited_on,
    SUM(window_day.amount) AS amount,
    ROUND(AVG(window_day.amount), 2) AS average_amount
FROM daily_sales AS current_day
JOIN daily_sales AS window_day
    ON window_day.visited_on
       BETWEEN current_day.visited_on - INTERVAL 6 DAY
           AND current_day.visited_on
GROUP BY current_day.visited_on
HAVING COUNT(*) = 7
ORDER BY current_day.visited_on;