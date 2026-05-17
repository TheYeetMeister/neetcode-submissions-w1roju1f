-- Write your query below

SELECT 
    user_id,
    MAX(next_visit_date - visit_date) AS biggest_window
FROM (
    SELECT
        user_id,
        visit_date,
        LEAD(visit_date, 1, '2021-1-1') OVER (
            PARTITION BY user_id
            ORDER BY visit_date 
        ) AS next_visit_date
    FROM user_visits
)
GROUP BY user_id;
