-- Last updated: 6/10/2026, 11:44:53 AM
# Write your MySQL query statement below
SELECT tweet_id  FROM Tweets
WHERE length(trim(content))  > 15;