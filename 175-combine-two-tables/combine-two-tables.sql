# Write your MySQL query statement below
SELECT p.firstName , p.lastName,city,state  FROM 
    Person p left join Address a
    on p.personId = a.personId 
