-- Last updated: 9/6/2026, 3:57:35 PM
# Write your MySQL query statement below
-- select xx.pd  as product_id , round(sum(xx.newPrices)/sum(xx.numberUnits),2)   as average_price
-- from 
-- (   
--         select Prices.product_id as pd ,Prices.price *units  as newPrices ,units as numberUnits 
--         from  UnitsSold  ,Prices
--         where UnitsSold.product_id = Prices.product_id 
--         and purchase_date >= Prices.start_date 
--         and purchase_date  <= Prices.end_date    
-- ) as xx
-- group by xx.pd;
#---------------------------------------
/*
ROUND(
        IFNULL(SUM(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END) * 1.0 / COUNT(*), 0),
        3
    ) AS confirmation_rate
*/
select 
    p.product_id,
    round(ifnull(sum(p.price*us.units)*1.0 / sum(us.units),0),2)  as average_price
from 
    Prices p
left join 
    UnitsSold us
on 
    us.product_id = p.product_id  and us.purchase_date >= p.start_date and us.purchase_date  <= p.end_date 
group by
    p.product_id;
