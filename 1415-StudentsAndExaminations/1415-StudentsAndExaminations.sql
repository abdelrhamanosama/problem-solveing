-- Last updated: 6/10/2026, 11:46:45 AM
SELECT
    s.student_id,
    s.student_name,
    subj.subject_name,
    COUNT(e.subject_name) AS attended_exams
FROM
    Students AS s
CROSS JOIN
    Subjects AS subj
LEFT JOIN
    Examinations AS e
ON
    s.student_id = e.student_id
    AND subj.subject_name = e.subject_name
GROUP BY
    s.student_id,
    s.student_name,
    subj.subject_name
ORDER BY
    s.student_id,
    subj.subject_name;
