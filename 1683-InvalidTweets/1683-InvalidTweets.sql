-- Last updated: 9/6/2026, 2:21:49 PM
# Write your MySQL query statement below
SELECT tweet_id  FROM Tweets
WHERE length(trim(content))  > 15;