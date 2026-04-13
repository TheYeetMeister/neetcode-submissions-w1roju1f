-- Write your query below
SELECT a.player_id, MIN(a.event_date) as first_login
FROM activity as a
GROUP BY a.player_id;