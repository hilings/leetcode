#   196. Delete Duplicate Emails
#   2016-03-22
#####################################################

DROP TABLE IF EXISTS `Person`;


CREATE TABLE `Person` (
    `Id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `Email` VARCHAR(32),
    PRIMARY KEY (`Id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Person
(Email)
VALUES
('john@example.com'),
('bob@example.com'),
('john@example.com');


SELECT * FROM Person;

#####################################################
# Write your MySQL query statement below

DELETE FROM Person
WHERE id NOT IN (
    SELECT id FROM (
        SELECT MIN(id) id
        FROM Person
        GROUP BY email
    ) AS id_unique
);


#####################################################
# Write your MySQL query statement below

DELETE t2
FROM Person t1, Person t2
WHERE t1.email = t2.email
AND t1.Id < t2.Id;


