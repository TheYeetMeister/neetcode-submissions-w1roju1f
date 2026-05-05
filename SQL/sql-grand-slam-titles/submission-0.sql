-- Write your query below

SELECT 
    p.player_id,
    p.player_name,
    SUM(
        COALESCE(wim.wimbleWins, 0) +
        COALESCE(fr.frWins, 0) +
        COALESCE(us.usWins, 0) +
        COALESCE(au.auWins, 0)
    ) AS grand_slams_count
FROM players AS p
LEFT JOIN (
    SELECT ch.wimbledon AS player_id, COUNT(ch.wimbledon) AS wimbleWins
    FROM championships AS ch
    GROUP BY ch.wimbledon
) AS wim ON p.player_id = wim.player_id
LEFT JOIN (
    SELECT fr.fr_open AS player_id, COUNT(fr.fr_open) AS frWins
    FROM championships AS fr
    GROUP BY fr.fr_open
) AS fr ON p.player_id = fr.player_id
LEFT JOIN (
    SELECT us.us_open AS player_id, COUNT(us.us_open) AS usWins
    FROM championships AS us
    GROUP BY us.us_open
) AS us ON p.player_id = us.player_id
LEFT JOIN (
    SELECT au.au_open AS player_id, COUNT(au.au_open) AS auWins
    FROM championships AS au
    GROUP BY au.au_open
) AS au ON p.player_id = au.player_id
GROUP BY p.player_id, p.player_name
HAVING SUM(
    COALESCE(wim.wimbleWins, 0) +
    COALESCE(fr.frWins, 0) +
    COALESCE(us.usWins, 0) +
    COALESCE(au.auWins, 0)
) > 0;
