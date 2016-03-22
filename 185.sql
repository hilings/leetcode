#   185.Department Top Three Salaries
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
('Max', 90000, 1),
('Janet', 69000, 1),
('Randy', 85000, 1);


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


#####################################################
# Write your MySQL query statement below

SELECT
    d.Name Department,
    t.Name Employee,
    t.Salary Salary
FROM Department d
JOIN (
    SELECT
        e.DepartmentId,
        e.Name,
        e.Salary,
        CASE
            WHEN @previd = e.DepartmentId AND e.Salary = @prevsalary THEN @rank := @rank
            WHEN @previd = e.DepartmentId AND e.Salary < @prevsalary THEN @rank := @rank + 1
            ELSE @rank := 1
        END rank,
        @previd := e.DepartmentId,
        @prevsalary := e.Salary
    FROM Employee e, (SELECT @previd := NULL, @prevsalary := NULL, @rank := 0) r
    ORDER BY e.DepartmentId, e.Salary DESC
) t
    ON d.Id = t.DepartmentId
    AND t.rank <= 3;


