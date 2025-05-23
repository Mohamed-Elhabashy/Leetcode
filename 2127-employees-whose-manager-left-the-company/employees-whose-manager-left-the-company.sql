# Write your MySQL query statement below
SELECT employee_id 
FROM Employees as e
WHERE salary < 30000
AND manager_id IS NOT NULL
AND (
    SELECT 
    NOT EXISTS(
        SELECT 1
        FROM Employees as e2
        WHERE e2.employee_id = e.manager_id
    )
)
ORDER BY employee_id