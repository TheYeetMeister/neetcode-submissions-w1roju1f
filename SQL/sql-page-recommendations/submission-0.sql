-- Write your query below

SELECT DISTINCT l.page_id AS recommended_page
FROM likes AS l
JOIN friendship AS f ON l.user_id = f.user1_id OR l.user_id = f.user2_id
WHERE (f.user1_id = 1 OR f.user2_id = 1) AND l.page_id NOT IN (
    SELECT page_id
    FROM likes
    WHERE user_id = 1
);
