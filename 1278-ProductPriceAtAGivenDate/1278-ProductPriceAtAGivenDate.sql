-- Last updated: 6/10/2026, 11:47:05 AM
# Write your MySQL query statement below
SELECT 
    t.product_id, 
    10 AS price
FROM (
    SELECT  
        product_id, 
        MIN(change_date) AS tt
    FROM Products 
    GROUP BY product_id 
    HAVING MIN(change_date) > '2019-08-16'
) AS t

UNION ALL

SELECT 
    f.product_id, 
    f.new_price AS price
FROM (
    SELECT  
        k.product_id,  
        k.new_price
    FROM Products k
    WHERE k.change_date <= '2019-08-16'
    AND (k.product_id, k.change_date) IN (
        SELECT product_id, MAX(change_date)
        FROM Products
        WHERE change_date <= '2019-08-16'
        GROUP BY product_id
    )
) AS f;
