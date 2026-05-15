-- Write your query below
WITH adjacency AS (
    SELECT
        log_id,
        LEAD(log_id, 1) OVER (ORDER BY log_id) AS next_id,
        LEAD(log_id, 1) OVER (ORDER BY log_id DESC) AS prev_id
    FROM logs
),
startId AS (
    SELECT 
        ROW_NUMBER() OVER (ORDER BY log_id) AS row_num,
        log_id
    FROM adjacency
    WHERE prev_id IS NULL OR NOT prev_id + 1 = log_id
),
endId AS (
    SELECT 
        ROW_NUMBER() OVER (ORDER BY log_id) AS row_num,
        log_id
    FROM adjacency
    WHERE next_id IS NULL OR NOT next_id - 1 = log_id
)

SELECT s.log_id AS start_id, e.log_id AS end_id
FROM startId AS s
JOIN endId AS e ON s.row_num = e.row_num;