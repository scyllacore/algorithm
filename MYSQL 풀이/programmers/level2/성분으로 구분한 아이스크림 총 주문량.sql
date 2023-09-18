SELECT icecream_info.ingredient_type AS 'INGREDIENT_TYPE',
       SUM(first_half.total_order)   AS 'TOTAL_ORDER'
FROM   first_half
       INNER JOIN icecream_info
               ON first_half.flavor = icecream_info.flavor
GROUP  BY ingredient_type
ORDER  BY total_order ASC 

/*
SELECT *
FROM FIRST_HALF INNER JOIN ICECREAM_INFO 
ON FIRST_HALF.FLAVOR = ICECREAM_INFO.FLAVOR
*/

/*
SELECT *
FROM FIRST_HALF INNER JOIN ICECREAM_INFO 
ON FIRST_HALF.FLAVOR = ICECREAM_INFO.FLAVOR
GROUP BY ICECREAM_INFO.INGREDIENT_TYPE
*/