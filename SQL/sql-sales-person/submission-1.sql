-- Write your query below

SELECT s.name
FROM sales_person s
WHERE s.sales_id NOT IN (
    select o.sales_id
    FROM company c, orders o
    WHERE o.com_id = c.com_id AND c.name = 'CRIMSON'
);