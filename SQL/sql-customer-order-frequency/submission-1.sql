-- Write your query below

SELECT c.customer_id, c.name
FROM customers AS c
JOIN orders AS o ON c.customer_id = o.customer_id AND 
    o.order_date >= '2020-07-01' AND o.order_date < '2020-08-01'
JOIN orders AS o2 ON c.customer_id = o2.customer_id AND 
    o2.order_date >= '2020-06-01' AND o2.order_date < '2020-07-01'
JOIN product AS p ON o.product_id = p.product_id
JOIN product AS p2 ON o2.product_id = p2.product_id
GROUP BY c.customer_id, c.name
HAVING SUM(p.price * o.quantity) >= 100 AND SUM(p2.price * o2.quantity) >= 100;