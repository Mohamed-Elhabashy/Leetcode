select R.contest_id,ROUND((count(*)*100.00/(SELECT COUNT(*) FROM Users)),2) as percentage 
from Users as U 
join Register as R
on U.user_id = R.user_id
group by R.contest_id
order by percentage DESC , R.contest_id
