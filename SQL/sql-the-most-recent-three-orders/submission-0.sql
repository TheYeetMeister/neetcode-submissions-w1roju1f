-- Write your query below
SELECT c.name AS customer_name, c.customer_id, topThree.order_id, topThree.order_date
FROM customers AS c
JOIN (
    SELECT 
        ROW_NUMBER() OVER (PARTITION BY o.customer_id ORDER BY o.order_date DESC) AS cnt,
        o.customer_id,
        o.order_id,
        o.order_date
    FROM orders AS o
) AS topThree ON topThree.cnt <= 3 AND topThree.customer_id = c.customer_id
ORDER BY c.name, c.customer_id, topThree.order_date DESC;