-- Last updated: 9/6/2026, 4:02:29 PM
# Write your MySQL query statement below
with filterPairs as (
    select 
        i1.tiv_2015,
        i1.tiv_2016
        from 
            Insurance as i1
        where not EXISTS (
            select 
                1
            from 
                Insurance as i2
            where 
                i2.pid<>i1.pid and i1.lat=i2.lat and i1.lon = i2.lon
        )
        and 
            exists (
                select 1
                from
                    Insurance as i3
                where 
                    i3.pid<>i1.pid and i1.tiv_2015 = i3.tiv_2015

            )

)
, canInvest as(
select 
    count(tiv_2015) as tiv_2015,
    sum(tiv_2016) as tiv_2016
from 
    filterPairs
group by tiv_2015

)
select 
    round(sum(tiv_2016), 2) as tiv_2016
from 
    canInvest

