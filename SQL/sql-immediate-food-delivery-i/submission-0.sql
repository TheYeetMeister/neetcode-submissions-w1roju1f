-- Write your query below

SELECT ROUND((immediate_deliveries / deliveries::numeric) * 100, 2) AS immediate_percentage
FROM (
    SELECT 
    SUM(
        CASE 
            WHEN d.order_date = d.customer_pref_delivery_date THEN 1
            ELSE 0
        END
    ) AS immediate_deliveries,
    COUNT(*) AS deliveries
    FROM delivery AS d
);