-- Last updated: 9/6/2026, 3:59:32 PM
# Write your MySQL query statement below
SELECT DISTINCT author_id as id FROM Views 
WHERE author_id  = viewer_id 
ORDER BY author_id;