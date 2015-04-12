#   184
#   Department Highest Salary
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
('Max', 90000, 1);


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
    t2.max Salary
FROM Employee e
JOIN (
    SELECT
        DepartmentId,
        MAX(Salary) max
    FROM Employee
    GROUP BY DepartmentId
) t2
    ON t2.DepartmentId = e.DepartmentId
    AND t2.max = e.Salary
JOIN Department d
    ON d.Id = e.DepartmentId
ORDER BY Salary DESC;

