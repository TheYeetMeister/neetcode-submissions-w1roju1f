-- Write your query below

SELECT 
    e.left_operand, 
    e.operator, 
    e.right_operand,
    CASE 
        WHEN e.operator = '>' THEN vLeft.value > vRight.value
        WHEN e.operator = '<' THEN vLeft.value < vRight.value
        ELSE vLeft.value = vRight.value
    END as value
FROM expressions e
JOIN variables vLeft ON e.left_operand = vLeft.name
JOIN variables vRight on e.right_operand = vRight.name;