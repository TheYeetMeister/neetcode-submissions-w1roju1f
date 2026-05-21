-- Write your query below

WITH recursive tasks_cnt AS (
    SELECT task_id, subtasks_count, 1 AS subtask_id
    FROM tasks

    UNION ALL

    SELECT task_id, subtasks_count, subtask_id + 1
    FROM tasks_cnt
    WHERE subtask_id < subtasks_count
)

SELECT task_id, subtask_id
FROM tasks_cnt AS t
WHERE NOT EXISTS (
    SELECT *
    FROM executed AS e
    WHERE 
        t.task_id = e.task_id AND
        t.subtask_id = e.subtask_id
);