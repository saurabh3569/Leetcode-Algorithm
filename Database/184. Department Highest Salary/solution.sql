SELECT 
    d.name AS Department,
    e.name AS Employee, 
    e.salary
FROM Employee e
INNER JOIN Department d ON d.id = e.departmentId
WHERE e.salary = (
    SELECT MAX(salary) FROM Employee e2 
    WHERE e.departmentId = e2.departmentId
)