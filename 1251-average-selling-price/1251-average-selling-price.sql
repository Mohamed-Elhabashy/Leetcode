select 
P.product_id ,
ROUND(SUM(cast(P.price as float) * U.units) / SUM(U.units),2) AS average_price
from Prices as P 
right join UnitsSold as U
on P.product_id = U.product_id and U.purchase_date >= P.start_date and U.purchase_date <= P.end_date
group by P.product_id