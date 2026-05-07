-- Write your query below

SELECT s.id, s.name
FROM students AS s
WHERE NOT EXISTS (
    SELECT *
    FROM departments AS d
    WHERE d.id = s.department_id
);