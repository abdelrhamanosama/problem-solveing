-- Last updated: 9/6/2026, 3:58:35 PM
-- -- # Write your MySQL query statement below
-- select 
--     DATE_FORMAT(trans_date,'%Y-%m') as  month,
--     country ,
--     count(id) as trans_count,
--     sum(case when state = 'approved' then 1 else 0 END) as approved_count ,
--     sum (amount) as trans_total_amount,
--     sum(case when state = 'approved' then amount else 0 END )as approved_total_amount
-- from  
--     Transactions 
-- group by 
--     month ,
--     country;

SELECT 
    DATE_FORMAT(trans_date,'%Y-%m') AS month,
    country,
    COUNT(id) AS trans_count,
    SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
FROM Transactions
GROUP BY 
    month,
    country;