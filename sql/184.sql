#   184.Department Highest Salary
#####################################################

DROP TABLE IF EXISTS `Employee`;


CREATE TABLE `Employee` (
    `Id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `Name` VARCHAR(16),
    `Salary` INT(8),
    `DepartmentId` INT(4),
    PRIMARY KEY (`Id`),
    KEY (`DepartmentId`)
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
    `Id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `Name` VARCHAR(16),
    PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Department
(Name)
VALUES
('IT'),
('Sales');


SELECT * FROM Department;

#####################################################
# Write your MySQL query statement below

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


#####################################################
# Write your MySQL query statement below

SELECT
    t.Name Department,
    e.Name Employee,
    e.Salary Salary
FROM Employee e
JOIN (
    SELECT
        d.Id,
        d.Name,
        MAX(e.Salary) ms
    FROM Department d
    JOIN Employee e
        ON e.DepartmentId = d.Id
    GROUP BY d.Id
) t
    ON e.DepartmentId = t.Id
    AND e.Salary = t.ms
ORDER BY e.Salary DESC;


