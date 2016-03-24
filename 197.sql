#   197. Rising Temperature
#   2016-03-22
#####################################################

DROP TABLE IF EXISTS `Weather`;


CREATE TABLE `Weather` (
    `Id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,
    `Date` DATE,
    `Temperature` INT(4),
    PRIMARY KEY (`Id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Weather
(Date, Temperature)
VALUES
('2015-01-01', 10),
('2015-01-02', 25),
('2015-01-03', 20),
('2015-01-04', 30);


SELECT * FROM Weather;

#####################################################
# Write your MySQL query statement below

SELECT Id
FROM Weather w
WHERE Temperature > (
    SELECT Temperature
    FROM Weather
    WHERE Date = DATE_SUB(w.Date, INTERVAL 1 DAY)
);


#####################################################
# Write your MySQL query statement below

SELECT t1.Id
FROM Weather t1, Weather t2
WHERE DATEDIFF(t1.Date, t2.Date) = 1
AND t1.Temperature > t2.Temperature;


#####################################################
# Write your MySQL query statement below

SELECT prev Id
FROM (
    SELECT
        CASE
            WHEN w.Temperature > @prev AND DATEDIFF(w.Date, @yesterday) = 1 THEN w.Id
        END prev,
        @yesterday := w.Date,
        @prev := w.Temperature
    FROM Weather w
    ORDER BY Date
) t
WHERE t.prev IS NOT NULL;


