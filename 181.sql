#   181
#   Employees Earning More Than Their Managers
#####################################################

DROP TABLE IF EXISTS `Employee`;


CREATE TABLE `Employee` (
    `Id` TINYINT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `Name` VARCHAR(32),
    `Salary` INT(8),
    `ManagerId` SMALLINT(4),
    PRIMARY KEY (`Id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Employee
(Name, Salary, ManagerId)
VALUES
('Joe', 70000, 3),
('Henry', 80000, 4),
('Sam', 60000, NULL),
('Max', 90000, NULL);


SELECT * FROM Employee;

#####################################################

SELECT t1.Name
FROM Employee t1
WHERE t1.Salary > (
    SELECT Salary
    FROM Employee t2
    WHERE t2.Id = t1.ManagerId
);


SELECT t1.Name
FROM Employee t1
JOIN Employee t2
    ON t1.ManagerId = t2.id
WHERE t1.Salary > t2.Salary;

