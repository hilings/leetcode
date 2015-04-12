#   176
#   Second Highest Salary
#####################################################

DROP TABLE IF EXISTS `Employee`;


CREATE TABLE `Employee` (
    `Id` TINYINT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `Salary` INT(8),
    PRIMARY KEY (`Id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Employee
(Salary)
VALUES
(100),
(200),
(300);


SELECT * FROM Employee;

#####################################################

SELECT MAX(Salary)
FROM Employee
WHERE Salary < (
    SELECT MAX(Salary)
    FROM Employee
);    

