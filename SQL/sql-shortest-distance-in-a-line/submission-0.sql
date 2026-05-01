-- Write your query below

SELECT 
  MIN(ABS(point1.x - point2.x)) AS shortest
FROM (
    SELECT 
    ROW_NUMBER() OVER (ORDER BY point) AS id,
    x
    FROM point
) AS point1
JOIN (
    SELECT 
    ROW_NUMBER() OVER (ORDER BY point) AS id,
    x
    FROM point
) AS point2 ON point1.id = point2.id - 1 OR point1.id = point2.id + 1;