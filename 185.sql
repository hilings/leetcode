#   185
#   Department Top Three Salaries
#####################################################

DROP TABLE IF EXISTS `Employee`;


CREATE TABLE `Employee` (
    `Id` INT NOT NULL AUTO_INCREMENT,
    `Name` VARCHAR(16),
    `Salary` INT,
    `DepartmentId` INT,
    PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Employee
(Name, Salary, DepartmentId)
VALUES
('Joe', 70000, 1),
('Henry', 80000, 2),
('Sam', 60000, 2),
('Max', 90000, 1),
('Janet', 69000, 1),
('Randy', 85000, 1);


SELECT * FROM Employee;

########

DROP TABLE IF EXISTS `Department`;


CREATE TABLE `Department` (
    `Id` INT NOT NULL AUTO_INCREMENT,
    `Name` VARCHAR(8),
    PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Department
(Name)
VALUES
('IT'),
('Sales');


SELECT * FROM Department;

#####################################################

SELECT
    d.Name Department,
    e.Name Employee,
    e.Salary
FROM Employee e
JOIN (
    SELECT DISTINCT
        DepartmentId,
        Salary
    FROM Employee
) t2
    ON e.DepartmentId = t2.DepartmentId
    AND e.Salary <= t2.Salary
JOIN Department d
    ON d.Id = e.DepartmentId
GROUP BY e.Id
HAVING count(*) <= 3
ORDER BY d.Id, e.Salary DESC;

