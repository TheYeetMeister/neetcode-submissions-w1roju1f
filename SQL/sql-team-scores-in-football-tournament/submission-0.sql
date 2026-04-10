-- Write your query below

SELECT t.team_id, t.team_name, sum(COALESCE(num_points, 0)) as num_points
FROM (
    SELECT 
        t.team_id,
        CASE 
            WHEN m.host_goals > m.guest_goals THEN 3
            WHEN m.host_goals = m.guest_goals THEN 1
            ELSE 0
        END as num_points
    FROM teams t
    JOIN matches m on t.team_id = m.host_team
    UNION ALL
    SELECT 
        t.team_id,
        CASE 
            WHEN m.host_goals < m.guest_goals THEN 3
            WHEN m.host_goals = m.guest_goals THEN 1
            ELSE 0
        END as num_points
    FROM teams t
    JOIN matches m on t.team_id = m.guest_team
) teamPts
RIGHT JOIN teams t ON teamPts.team_id = t.team_id
GROUP BY t.team_id, t.team_name
ORDER BY num_points DESC, t.team_id;