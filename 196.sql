#   196
#   Delete Duplicate Emails
#####################################################

DROP TABLE IF EXISTS `Person`;


CREATE TABLE `Person` (
    `id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `email` VARCHAR(32),
    PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Person
(email)
VALUES
('john@example.com'),
('bob@example.com'),
('john@example.com');


SELECT * FROM Person;

#####################################################

SELECT *
#DELETE
FROM Person
WHERE id NOT IN (
    SELECT id FROM (
        SELECT MIN(id) id
        FROM Person
        GROUP BY email
        #HAVING count(*) > 1
    ) AS id_unique
);

