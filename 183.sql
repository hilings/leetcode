#   183
#   Customers Who Never Order
#####################################################

DROP TABLE IF EXISTS `Customers`;


CREATE TABLE `Customers` (
    `Id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `Name` VARCHAR(16),
    PRIMARY KEY (`Id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Customers
(Name)
VALUES
('Joe'),
('Henry'),
('Sam'),
('Max');


SELECT * FROM Customers;

#####################################################

DROP TABLE IF EXISTS `Orders`;


CREATE TABLE `Orders` (
    `Id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `CustomerId` INT(4) UNSIGNED NOT NULL,
    PRIMARY KEY (`Id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Orders
(CustomerId)
VALUES
(3),
(1);


SELECT * FROM Orders;

#####################################################

SELECT c.name Customers
FROM Customers c
LEFT JOIN Orders o
    ON c.Id = o.CustomerId
WHERE o.Id IS NULL;

