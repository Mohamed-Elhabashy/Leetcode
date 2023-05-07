/* Write your T-SQL query statement below */
select s.student_id,s.student_name ,sb.subject_name,count(e.subject_name) as attended_exams   from Students as s 
cross join Subjects as sb
left join Examinations as e 
on s.student_id = e.student_id and e.subject_name = sb.subject_name 
group by sb.subject_name,s.student_id,s.student_name
order by s.student_id,s.student_name
