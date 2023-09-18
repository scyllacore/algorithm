SELECT HOUR(datetime)  AS 'HOUR',
       COUNT(datetime) AS 'COUNT'
FROM   animal_outs
GROUP  BY hour
HAVING hour >= 9
       AND hour <= 19
ORDER  BY hour

/*
SELECT 
HOUR(DATETIME) AS 'HOUR',
COUNT(DATETIME) AS 'COUNT'
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME)>=9 AND HOUR(DATETIME)<=19
GROUP BY HOUR
ORDER BY HOUR
*/

# https://nohriter.tistory.com/129 -> 실행 순서


#https://velog.io/@kimmjieun/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%9E%85%EC%96%91-%EC%8B%9C%EA%B0%81-%EA%B5%AC%ED%95%98%EA%B8%B01