-- Write your query below
WITH success_date_diff AS (
    SELECT 
        success_date,
        (success_date::date - '2019-01-01'::date) - ROW_NUMBER() OVER (ORDER BY success_date) AS diff
    FROM succeeded
    WHERE success_date >= '2019-01-01' AND success_date < '2020-01-01'
),
fail_date_diff AS (
    SELECT 
        fail_date,
        (fail_date::date - '2019-01-01'::date) - ROW_NUMBER() OVER (ORDER BY fail_date) AS diff
    FROM failed
    WHERE fail_date >= '2019-01-01' AND fail_date < '2020-01-01'
)
SELECT *
FROM (
    SELECT
    'failed' AS period_state,
    MIN(fail_date) AS start_date,
    MAX(fail_date) AS end_date
    FROM fail_date_diff
    GROUP BY diff
    UNION ALL
    SELECT 
    'succeeded' AS period_state,
    MIN(success_date) AS start_date,
    MAX(success_date) AS end_date
    FROM success_date_diff
    GROUP BY diff
)
ORDER BY start_date;