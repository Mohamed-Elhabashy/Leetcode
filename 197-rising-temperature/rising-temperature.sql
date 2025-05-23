# Write your MySQL query statement below
SELECT d1.id
FROM Weather d1
JOIN Weather d2
ON DATEDIFF(d1.recordDate,d2.recordDate) = 1
WHERE d1.temperature > d2.temperature 