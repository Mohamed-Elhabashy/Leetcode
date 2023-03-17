# Write your MySQL query statement below
select sell_date,COUNT(DISTINCT(product)) AS num_sold,
group_concat(DISTINCT(product) order by product)as products
from Activities group by sell_date order by sell_date;