# Write your MySQL query statement below
SELECT DISTINCT a.Email as `Email`
FROM Person as a,
    Person as b
WHERE a.Id != b.Id
    and a.Email = b.Email;