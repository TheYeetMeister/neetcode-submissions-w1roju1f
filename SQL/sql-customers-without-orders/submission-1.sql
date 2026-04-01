-- Write your query below

SELECt name
FROM customers
WHERE id NOT IN (SELECT customer_id FROM orders);