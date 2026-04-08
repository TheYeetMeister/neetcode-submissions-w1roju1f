-- Write your query below

SELECT s.name
FROM sales_person s
WHERE NOT EXISTS (
    select *
    FROM company c, orders o
    WHERE o.com_id = c.com_id AND o.sales_id = s.sales_id AND c.name = 'CRIMSON'
);