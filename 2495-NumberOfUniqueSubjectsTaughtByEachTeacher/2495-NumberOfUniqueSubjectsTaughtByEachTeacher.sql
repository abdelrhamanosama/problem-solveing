-- Last updated: 6/10/2026, 11:42:48 AM
# Write your MySQL query statement below
SELECT
    teacher_id,
    COUNT(DISTINCT subject_id) AS cnt
FROM
    Teacher
GROUP BY
    teacher_id;