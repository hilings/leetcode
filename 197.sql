#   197
#   Rising Temperature
#####################################################

DROP TABLE IF EXISTS `Weather`;


CREATE TABLE `Weather` (
    `Id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `Date` DATE,
    `Temperature` INT(4) UNSIGNED NOT NULL,
    PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Weather
(Date, Temperature)
VALUES
('2015-01-01', 10),
('2015-01-02', 25),
('2015-01-03', 20),
('2015-01-04', 30);


SELECT * FROM Weather;

#####################################################

SELECT Id
FROM Weather w
WHERE Temperature > (
    SELECT Temperature
    FROM Weather
    WHERE Date = DATE_SUB(w.Date, INTERVAL 1 DAY)
);

