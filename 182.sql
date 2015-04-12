#   182
#   Duplicate Emails
#####################################################

DROP TABLE IF EXISTS `Person`;


CREATE TABLE `Person` (
    `Id` TINYINT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `Email` VARCHAR(32),
    PRIMARY KEY (`Id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Person
(Email)
VALUES
('a@b.com'),
('c@d.com'),
('a@b.com');


SELECT * FROM Person;

#####################################################

SELECT Email
FROM Person
GROUP BY Email
HAVING count(Email) > 1;

