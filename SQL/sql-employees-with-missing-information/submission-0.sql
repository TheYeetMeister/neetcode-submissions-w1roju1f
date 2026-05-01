-- Write your query below

select COALESCE(e.employee_id, s.employee_id) AS employee_id
FROM employees AS e
FULL JOIN salaries AS s ON s.employee_id = e.employee_id
WHERE e.name IS NULL OR s.salary IS NULL
ORDER BY COALESCE(e.employee_id, s.employee_id);