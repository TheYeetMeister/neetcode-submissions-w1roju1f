-- Write your query below

SELECT a.seat_id
FROM cinema AS a
WHERE a.free = 1 AND exists (
    SELECT b.seat_id
    FROM cinema AS b
    WHERE (a.seat_id + 1 = b.seat_id OR a.seat_id - 1 = b.seat_id) AND b.free = 1
);