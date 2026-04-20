-- Write your query below

SELECT name, balance
FROM (
    SELECT u.name, SUM(t.amount) AS balance
    FROM users AS u
    JOIN transactions AS t ON u.account = t.account
    GROUP BY u.name
)
WHERE balance > 10000;