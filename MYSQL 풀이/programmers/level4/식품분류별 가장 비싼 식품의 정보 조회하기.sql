
SELECT CATEGORY, PRICE AS 'MAX_PRICE', PRODUCT_NAME 
FROM FOOD_PRODUCT
WHERE (CATEGORY, PRICE) IN (SELECT CATEGORY, MAX(PRICE)
                FROM FOOD_PRODUCT
                WHERE CATEGORY IN ('과자', '국', '김치', '식용유')
                GROUP BY CATEGORY)
ORDER BY PRICE DESC


/*
SELECT
    CATEGORY
    ,MAX(PRICE) AS 'MAX_PRICE' #
    ,PRODUCT_NAME # 위에 라인과 아래라인은 매칭되어 출력되지 않는다.
    #MAX는 가장 큰값으로 뜨지만, PRODUCT_NAME은 grouping되고 난 후 MAX된 것이 아닌 제일 위에 것으로 뜬다.
    #따라서 두 속성은 연관관계가 없다.
FROM
    FOOD_PRODUCT
WHERE 
    CATEGORY 
        IN ('과자','국','김치','식용유')
GROUP BY
    CATEGORY
ORDER BY PRICE DESC
*/