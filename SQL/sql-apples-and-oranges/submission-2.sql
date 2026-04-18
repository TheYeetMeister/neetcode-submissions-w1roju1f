SELECT
    a.sale_date,
    a.sold_num - o.sold_num AS diff
FROM sales a
JOIN sales o ON a.sale_date = o.sale_date
WHERE a.fruit = 'apples' AND o.fruit = 'oranges'
ORDER BY a.sale_date;