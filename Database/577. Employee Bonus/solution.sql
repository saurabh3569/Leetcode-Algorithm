select e.name as name, b.bonus as bonus from Employee e
left join Bonus b on b.empId = e.empId
where b.bonus < 1000 or b.empId is null