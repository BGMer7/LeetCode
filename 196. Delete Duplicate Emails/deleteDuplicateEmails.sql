# Write your MySQL query statement below
DELETE a
FROM Person as a,
    Person as b
WHERE a.Email = b.Email
    and a.Id > b.Id;