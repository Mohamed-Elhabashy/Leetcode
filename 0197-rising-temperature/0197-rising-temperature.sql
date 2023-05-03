/* Write your T-SQL query statement below */
SELECT x.id
FROM Weather x
JOIN Weather y ON x.recordDate = DATEADD(day,1,y.recordDate)
where x.temperature>y.temperature  

