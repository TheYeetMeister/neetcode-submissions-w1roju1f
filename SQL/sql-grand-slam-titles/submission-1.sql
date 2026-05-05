-- Write your query below

SELECT
    p.player_id,
    p.player_name,
    COUNT(*) AS grand_slams_count
FROM players p
JOIN (
    SELECT wimbledon AS player_id FROM championships
    UNION ALL
    SELECT fr_open FROM championships
    UNION ALL
    SELECT us_open FROM championships
    UNION ALL
    SELECT au_open FROM championships
) AS winners ON p.player_id = winners.player_id
GROUP BY p.player_id, p.player_name;
