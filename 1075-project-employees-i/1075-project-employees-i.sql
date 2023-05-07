select 
P.project_id ,ROUND(avg(cast(E.experience_years as decimal)),2) as average_years 
from Project as P 
left join Employee as E
on P.employee_id = E.employee_id
group by P.project_id  
