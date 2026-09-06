-- Last updated: 9/6/2026, 2:13:59 PM
WITH t1 AS (
    SELECT
        p1.product_id AS pid1,
        p2.product_id AS pid2
    FROM ProductPurchases p1
    JOIN ProductPurchases p2
        ON p1.user_id = p2.user_id
       AND p1.product_id < p2.product_id
),

t2 AS (
    SELECT
        pid1,
        pid2,
        COUNT(*) AS customer_count
    FROM t1
    GROUP BY pid1, pid2
    having customer_count >= 3
),

t3 AS (
    SELECT
        t2.pid1,
        t2.pid2,
        p.category AS product1_category,
        t2.customer_count
    FROM t2
    JOIN ProductInfo p
        ON t2.pid1 = p.product_id
)

SELECT
    t3.pid1 as product1_id,
    t3.pid2 as product2_id,
    t3.product1_category,
    p.category AS product2_category,
    t3.customer_count
FROM t3
JOIN ProductInfo p
    ON t3.pid2 = p.product_id
ORDER BY
    customer_count DESC,
    pid1 ASC,
    pid2 ASC;