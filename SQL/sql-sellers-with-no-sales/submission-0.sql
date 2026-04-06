-- Write your query below
SELECT s.seller_name
FROM seller s
WHERE NOT EXISTS (
    SELECT DISTINCT seller_id
    FROM orders o
    WHERE s.seller_id = o.seller_id AND
    o.sale_date BETWEEN '2020-1-1' AND '2020-12-31'
)
ORDER BY s.seller_name;