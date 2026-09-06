-- Last updated: 9/6/2026, 3:57:28 PM
SELECT
    st.student_id,
    st.student_name,
    sub.subject_name,
    COUNT(e.subject_name) AS attended_exams
FROM Students AS st
CROSS JOIN Subjects AS sub
LEFT JOIN Examinations AS e
    ON e.student_id = st.student_id
   AND e.subject_name = sub.subject_name
GROUP BY
    st.student_id,
    st.student_name,
    sub.subject_name
ORDER BY
    st.student_id,
    sub.subject_name;