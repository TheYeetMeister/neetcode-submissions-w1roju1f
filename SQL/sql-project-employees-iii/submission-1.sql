-- Write your query below

SELECT p.project_id, e.employee_id
FROM project AS p
JOIN employee AS e ON p.employee_id = e.employee_id
WHERE (p.project_id, e.experience_years) IN (
    SELECT p.project_id, MAX(e.experience_years)
    FROM project AS p
    JOIN employee AS e ON p.employee_id = e.employee_id
    GROUP BY p.project_id
);