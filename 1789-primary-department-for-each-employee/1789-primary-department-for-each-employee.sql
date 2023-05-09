/* Write your T-SQL query statement below */
with total as(
    select e1.employee_id,e1.department_id ,e1.primary_flag,counter
    from Employee as e1 
    join (select employee_id , count(*) as counter from Employee group by employee_id) as e2
    on e1.employee_id = e2.employee_id
)
select employee_id ,department_id  from total where counter=1 or primary_flag='Y'