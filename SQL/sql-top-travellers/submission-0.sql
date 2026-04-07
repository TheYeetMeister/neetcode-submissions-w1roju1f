-- Write your query below

SELECT 
    name, 
        CASE WHEN SUM(r.distance) IS NULL THEN 0
        ELSE SUM(r.distance)
    END AS travelled_distance
FROM users u
LEFT JOIN rides r ON u.id = r.user_id
GROUP BY name
ORDER BY travelled_distance DESC, name;