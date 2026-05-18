-- Write your query below
SELECT e1.employee_id
FROM employees e1
JOIN employees e2 ON e1.manager_id = e2.employee_id
LEFT JOIN employees e3 ON e2.manager_id = e3.employee_id
LEFT JOIN employees e4 ON e3.manager_id = e4.employee_id
WHERE e1.employee_id != 1
    AND (
        e1.manager_id = 1
        OR e2.manager_id = 1
        OR e3.manager_id = 1
    );