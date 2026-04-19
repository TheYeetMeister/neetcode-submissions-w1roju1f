-- Write your query below

SELECT callData.person1, callData.person2, COUNT(*) as call_count, SUM(callData.duration) AS total_duration
FROM (
    SELECT LEAST(c.from_id, c.to_id) as person1, GREATEST(c.from_id, c.to_id) as person2, c.duration
    FROM calls AS c
) AS callData
GROUP BY callData.person1, callData.person2;