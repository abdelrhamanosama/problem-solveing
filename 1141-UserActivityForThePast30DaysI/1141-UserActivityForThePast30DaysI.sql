-- Last updated: 9/6/2026, 3:59:39 PM
SELECT 
    activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE 
    activity_date BETWEEN DATE_SUB('2019-07-28', INTERVAL 30 DAY) 
    AND '2019-07-27' and activity_type is not null
GROUP BY 
    day;