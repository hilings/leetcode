#   177
#   Nth Highest Salary
#####################################################

DROP TABLE IF EXISTS `Employee`;


CREATE TABLE `Employee` (
    `Id` INT NOT NULL AUTO_INCREMENT,
    `Salary` INT,
    PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Employee
(Salary)
VALUES
(100),
(200),
(300);


SELECT * FROM Employee;

#####################################################

DROP FUNCTION IF EXISTS getNthHighestSalary;

DELIMITER $$

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE offset INT;
    SET offset = N - 1;
    
    RETURN (
        # Write your MySQL query statement below.
        SELECT DISTINCT Salary
        FROM Employee
        ORDER BY Salary DESC
        LIMIT offset, 1
    );
END
$$
DELIMITER ;


SELECT getNthHighestSalary(4);

