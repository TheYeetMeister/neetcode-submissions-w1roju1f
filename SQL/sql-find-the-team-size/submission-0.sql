-- Write your query below

SELECT e.employee_id, teamSize.team_size
FROM employee AS e
JOIN (
    SELECT team_id, COUNT(*) as team_size
    FROM employee
    GROUP BY team_id
) AS teamSize ON e.team_id = teamSize.team_id;