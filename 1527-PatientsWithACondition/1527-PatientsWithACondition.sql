-- Last updated: 9/6/2026, 2:22:42 PM
# Write your MySQL query statement below
select
    patient_id ,
    patient_name ,
    conditions 
from 
    Patients
WHERE conditions = 'DIAB1'
   OR conditions LIKE 'DIAB1%'
   OR conditions LIKE '% DIAB1__'
   OR conditions LIKE '% DIAB1__%'