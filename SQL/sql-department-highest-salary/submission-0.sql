-- Write your query below

SELECT d.name AS department, e.name AS employee, e.salary
FROM employee AS e
INNER JOIN (
    SELECT e.department_id, MAX(e.salary) AS highest_sal
    FROM employee AS e
    GROUP BY e.department_id
) AS t ON e.department_id = t.department_id AND e.salary = t.highest_sal
JOIN department AS d ON e.department_id = d.id;