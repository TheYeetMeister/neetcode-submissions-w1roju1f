-- Write your query below

SELECT t.customer_number
FROM (
    SELECT customer_number, COUNT(order_number) order_count
    FROM orders
    GROUP BY customer_number
) as t
ORDER BY t.order_count DESC
LIMIT 1;