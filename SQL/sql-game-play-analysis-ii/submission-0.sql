-- Write your query below

SELECT DISTINCT ON (player_id) player_id, device_id
FROM activity
ORDER BY player_id, event_date;