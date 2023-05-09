/* Write your T-SQL query statement below */
select coalesce(
    (select TOP 1  num as num from MyNumbers 
group by num having count(*)=1
order by num desc),null) as num;

