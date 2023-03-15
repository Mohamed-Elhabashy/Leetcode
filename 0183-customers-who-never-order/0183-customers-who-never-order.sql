# Write your MySQL query statement below
SELECT name AS Customers FROM Customers left join Orders on Customers.id = Orders.customerId WHERE Orders.customerId IS NULL;