select E.name as Employee from Employee E join Employee E2 on E.managerId = E2.id where E.salary > E2.salary;
