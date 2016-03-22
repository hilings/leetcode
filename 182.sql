#   182.Duplicate Emails
#####################################################

DROP TABLE IF EXISTS `Person`;


CREATE TABLE `Person` (
    `Id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `Email` VARCHAR(16),
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
# Write your MySQL query statement below

SELECT Email
FROM Person
GROUP BY Email
HAVING count(Email) > 1;


#####################################################
# Write your MySQL query statement below

SELECT DISTINCT Email
FROM (
    SELECT Email,
        CASE
            WHEN @prev = Email THEN Email
            WHEN @prev := Email THEN Email
        END e2
    FROM Person, (SELECT @prev := NULL) r
    ORDER BY Email
) t
WHERE e2 IS NOT NULL;


