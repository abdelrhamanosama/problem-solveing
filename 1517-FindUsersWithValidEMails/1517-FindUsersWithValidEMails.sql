-- Last updated: 9/6/2026, 2:22:50 PM
SELECT
    user_id,
    name,
    mail
FROM Users
WHERE   mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$'AND mail LIKE BINARY '%@leetcode.com' ;