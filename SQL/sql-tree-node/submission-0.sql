-- Write your query below

SELECT 
    DISTINCT treeParent.id AS id,
    CASE 
        WHEN treeParent.p_id IS NULL THEN 'Root'
        WHEN treeChildren.id IS NULL THEN 'Leaf'
        ELSE 'Inner' 
    END AS type
FROM tree AS treeParent
LEFT JOIN tree AS treeChildren ON treeParent.id = treeChildren.p_id;