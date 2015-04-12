#   178
#   Rank Scores
#####################################################

DROP TABLE IF EXISTS `Scores`;


CREATE TABLE `Scores` (
    `Id` INT NOT NULL AUTO_INCREMENT,
    `Score` DECIMAL(8, 2) ,
    PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;


INSERT INTO Scores
(Score)
VALUES

#(0.00);

#(-2.10), (0.00), (0.00), (2.00);

(3.50),
(3.65),
(4.00),
(3.85),
(4.00),
(3.65);


SELECT * FROM Scores;

#####################################################

SELECT
    Score,
    CASE
        WHEN @prev = Score THEN @rank
        WHEN @prev := Score THEN @rank := @rank + 1
        WHEN @rank := @rank + 1 THEN @rank
    END Rank
FROM Scores, (SELECT @rank := 0, @prev := NULL) r
ORDER BY Score DESC;

