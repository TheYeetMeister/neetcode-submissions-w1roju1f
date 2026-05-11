-- Write your query below

SELECT p.product_name, p.product_id, o.order_id, o.order_date
FROM orders AS o
INNER JOIN (
    SELECT o.product_id AS product_id, MAX(o.order_date) AS order_date
    FROM orders AS o
    JOIN products AS p ON o.product_id = p.product_id
    GROUP BY o.product_Id
) AS recBuy ON o.product_id = recBuy.product_id AND o.order_date = recBuy.order_date
JOIN products AS p ON recBuy.product_id = p.product_id
ORDER BY p.product_name, p.product_id, o.order_id;