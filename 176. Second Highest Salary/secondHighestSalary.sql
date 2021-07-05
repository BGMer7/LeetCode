select IFNULL (
        (
            SELECT DISTINCT Salary
            FROM Employee as SecondHighestSalary
            ORDER BY Salary DESC
            LIMIT 1, 1
        ), NULL
    ) as SecondHighestSalary;