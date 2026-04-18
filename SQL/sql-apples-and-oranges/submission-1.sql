-- Write your query below

SELECT 
    saleSum.sale_date, 
    SUM (
        CASE
            WHEN saleSum.fruit = 'apples' 
                THEN saleSum.fruitsSold
            ELSE -saleSum.fruitsSold
        END
    ) as diff
FROM (
    SELECT s.sale_date, s.fruit, SUM(s.sold_num) fruitsSold
    FROM sales AS s
    GROUP BY s.sale_date, s.fruit
) AS saleSum
GROUP BY saleSum.sale_date;