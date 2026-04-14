-- Write your query below

SELECT w.name as warehouse_name, SUM(p.width * p.length * p.height * w.units) as volume
FROM warehouse w
JOIN products p ON w.product_id = p.product_id
GROUP BY w.name;