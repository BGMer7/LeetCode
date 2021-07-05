# Write your MySQL query statement below
SELECT *
FROM cinema as c
WHERE mod(id, 2) = 1
    and description != 'boring'
ORDER BY rating DESC;