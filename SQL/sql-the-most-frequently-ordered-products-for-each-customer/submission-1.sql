-- Write your query below

WITH freq_cnt AS (
    SELECT customer_id, product_id, COUNT(*) frequency
    FROM orders
    GROUP BY customer_id, product_id
),
max_freq_cnt AS (
    SELECT customer_id, MAX(frequency) AS max_freq
    FROM freq_cnt
    GROUP BY customer_id
)
SELECT cnt.customer_id, cnt.product_id, p.product_name
FROM freq_cnt AS cnt
JOIN products AS p ON cnt.product_id = p.product_id
INNER JOIN customers AS c ON c.customer_id = cnt.customer_id
WHERE (cnt.customer_id, cnt.product_id) IN (
    SELECT customer_id, product_id
    FROM freq_cnt
    WHERE (customer_id, frequency) IN (
        SELECT customer_id, max_freq
        FROM max_freq_cnt
    )
);