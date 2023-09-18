SELECT product_id,
       product_name,
       product_cd,
       category,
       price
FROM   food_product
WHERE  price IN (SELECT MAX(price)
                 FROM   food_product) 
                 
/*
SELECT PRODUCT_ID, PRODUCT_NAME, PRODUCT_CD, CATEGORY, PRICE
FROM FOOD_PRODUCT
ORDER BY PRICE DESC
LIMIT 1
*/