#   180
#   Consecutive Numbers
#####################################################

DROP TABLE IF EXISTS `Logs`;


CREATE TABLE `Logs` (
    `Id` INT NOT NULL AUTO_INCREMENT,
    `Num` INT,
    PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Logs
(Num)
VALUES
(1),
(1),
(1),
(2),
(1),
(2),
(2);


SELECT * FROM Logs;

#####################################################

SELECT DISTINCT t2.cur
FROM (
    SELECT
        CASE
            WHEN (@prev2 = Num AND @prev1 = Num) THEN Num
            ELSE NULL
        END cur,
        @prev2 := @prev1,
        @prev1 := Num
    FROM Logs, (SELECT @prev1 := NULL, @prev2 := NULL) r
) t2
WHERE t2.cur IS NOT NULL;

