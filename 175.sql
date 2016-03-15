#   175
#   Combine Two Tables
#####################################################

DROP TABLE IF EXISTS `Person`;


CREATE TABLE `Person` (
    `PersonId` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `FirstName` VARCHAR(32),
    `LastName` VARCHAR(32),
    PRIMARY KEY (`PersonId`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Person
(FirstName, LastName)
VALUES
('aaa', 'zzz'),
('bbb', 'yyy'),
('ccc', 'xxx');


SELECT * FROM Person;

#####################################################

DROP TABLE IF EXISTS `Address`;


CREATE TABLE `Address` (
    `AddressId` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `PersonId` INT(4),
    `City` VARCHAR(32),
    `State` VARCHAR(32),
    PRIMARY KEY (`AddressId`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Address
(PersonId, City, State)
VALUES
(1, 'Seattle', 'WA'),
(3, 'Bellevue', 'WA');


SELECT * FROM Address;

#####################################################
# Write your MySQL query statement below

SELECT FirstName, LastName, City, State
FROM Person
LEFT JOIN Address
    ON Person.PersonId = Address.PersonId;


#####################################################
# Write your MySQL query statement below

SELECT
    p.FirstName,
    p.LastName,
    a.City,
    a.State
FROM Person p
LEFT JOIN Address a
    ON p.PersonId = a.PersonId
;

