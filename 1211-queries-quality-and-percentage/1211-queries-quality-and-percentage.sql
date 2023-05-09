/* Write your T-SQL query statement below */
select query_name,
round(sum(rating*1.0 / position )/count(*),2) as  quality,
round(sum(IIF(rating<3,1.00,0.00))/count(*)*100,2) as  poor_query_percentage
from Queries
group by query_name 