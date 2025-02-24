WITH R1 AS(
SELECT IF(LENGTH IS NULL,10,LENGTH) AS LENGTH
FROM FISH_INFO
)

SELECT ROUND(SUM(LENGTH)/COUNT(LENGTH),2) AS AVERAGE_LENGTH
FROM R1