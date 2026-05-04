-- Write your query below

SELECT a.player_id, a.event_date, SUM(b.games_played) AS games_played_so_far
FROM activity AS a
JOIN activity AS b ON a.player_id = b.player_id AND a.event_date >= b.event_date
GROUP BY a.player_id, a.event_date;