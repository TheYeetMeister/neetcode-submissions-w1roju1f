-- Write your query below
SELECT 
    countryStat.name AS country
FROM (SELECT 
    cou.name,
    c.duration
FROM calls as c
JOIN person AS p1 ON p1.id = c.caller_id
JOIN country AS cou 
    ON p1.phone_number LIKE cou.country_code || '-%' 
UNION ALL
SELECT 
    cou.name,
    c.duration
FROM calls as c
JOIN person AS p2 ON p2.id = c.callee_id
JOIN country AS cou 
    ON p2.phone_number LIKE cou.country_code || '-%') AS countryStat
GROUP BY countryStat.name
HAVING AVG(countryStat.duration) > (SELECT AVG(duration) AS total FROM calls);
