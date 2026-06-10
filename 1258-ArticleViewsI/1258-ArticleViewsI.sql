-- Last updated: 6/10/2026, 11:47:06 AM
# Write your MySQL query statement below
SELECT DISTINCT author_id as id FROM Views 
WHERE author_id  = viewer_id 
ORDER BY author_id;