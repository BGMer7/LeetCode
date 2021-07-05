# Write your MySQL query statement below
SELECT DISTINCT b.Id
FROM Weather as a,
    Weather as b
WHERE a.Temperature < b.Temperature
    and DATEDIFF(a.recordDate, b.recordDate) = -1;