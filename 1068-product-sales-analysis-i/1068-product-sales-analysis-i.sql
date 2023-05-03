/* Write your T-SQL query statement below */
select product_name ,year ,price from sales  s
inner join Product  p
on s.product_id = p.product_id 