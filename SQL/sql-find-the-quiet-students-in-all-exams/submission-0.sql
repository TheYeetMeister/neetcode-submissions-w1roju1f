-- Write your query below

WITH loud_students AS (
    SELECT DISTINCT e.student_id
    FROM exam AS e
    JOIN (
        SELECT exam_id, MAX(score) highest, MIN(score) lowest
        FROM exam
        GROUP BY exam_id
    ) AS t ON t.exam_id = e.exam_id AND (t.highest = e.score OR t.lowest = e.score)
)

SELECT student_id, student_name
FROM student
WHERE student_id IN (
    SELECT student_id
    FROM exam
) AND student_id NOT IN (
    select *
    FROM loud_students
);
