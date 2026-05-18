-- Write your query below
SELECT *
FROM (
    SELECT employee_id
    FROM employees
    WHERE manager_id = 1
    UNION
    SELECT s.employee_id
    FROM employees AS f
    JOIN employees AS s ON s.manager_id = f.employee_id
    WHERE f.manager_id = 1
    UNION
    SELECT th.employee_id
    FROM employees AS f
    JOIN employees AS s ON s.manager_id = f.employee_id
    JOIN employees AS th ON th.manager_id = s.employee_id
    WHERE f.manager_id = 1)
WHERE employee_id != 1;