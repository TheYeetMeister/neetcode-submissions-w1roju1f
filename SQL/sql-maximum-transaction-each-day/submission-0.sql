-- Write your query below

SELECT t.transaction_id
FROM transactions AS t
INNER JOIN (
    SELECT DATE(m.day) AS day, MAX(amount) AS maxAmount
    FROM transactions AS m
    GROUP BY DATE(m.day)
) AS maxAmt ON DATE(t.day) = maxAmt.day AND t.amount = maxAmt.maxAmount
ORDER BY t.transaction_id;