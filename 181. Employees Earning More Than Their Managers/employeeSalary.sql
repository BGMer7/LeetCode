# Write your MySQL query statement below
SELECT a.Name as `Employee`
FROM Employee as a,
    Employee as b
WHERE a.ManagerId = b.Id
    and a.Salary > b.Salary;