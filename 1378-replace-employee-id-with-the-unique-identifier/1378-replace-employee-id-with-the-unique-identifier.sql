/* Write your T-SQL query statement below */
select unique_id ,name from Employees as Emp
left join EmployeeUNI as EmpUni
on Emp.id = EmpUni.id