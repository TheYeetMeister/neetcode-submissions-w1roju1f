-- Write your query below

SELECT id, name
FROM students
WHERE department_id IS NULL OR department_id NOT IN (
    SELECT id
    FROM departments
);