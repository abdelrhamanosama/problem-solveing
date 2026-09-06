-- Last updated: 9/6/2026, 4:04:36 PM
DELETE p1
FROM Person p1
join Person p2
on p1.email = p2.email and p1.id > p2.id;
