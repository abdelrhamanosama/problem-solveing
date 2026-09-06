-- Last updated: 9/6/2026, 3:59:28 PM
# Write your MySQL query statement below
select 
    round(sum(
        case when d.customer_id = t.customer_id and t.diff = 0 and d.order_date  = t.mnd then 1 else 0 end
    )*1.0/count( distinct d.customer_id )*100,2)
    as immediate_percentage 
from 
    Delivery as d , (
select
    customer_id,datediff(min(customer_pref_delivery_date) ,min(order_date))  as diff ,
    min(order_date)  as mnd
from 
    Delivery 
group by customer_id 

     )as t 

