# Write your MySQL query statement below
SELECT 
    Department.name as 'Department', 
    Employee.name as 'Employee', 
    Salary as 'Salary'
FROM
    Employee 
    left JOIN Department
    on Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId, Salary)
    IN (SELECT DepartmentId, max( Salary ) 
        FROM Employee 
        GROUP BY DepartmentId)
AND Department.name is not null
