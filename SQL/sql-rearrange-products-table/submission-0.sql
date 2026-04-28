-- Write your query below

select main.product_id, sub.store, sub.price
FROM products AS main
CROSS JOIN LATERAL (
    VALUES 
        ('store1', store1), 
        ('store2', store2), 
        ('store3', store3)
) AS sub(store, price)
WHERE sub.price IS NOT NULL;