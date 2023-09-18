SELECT product.product_code                           AS PRODUCT_CODE,
       SUM(product.price * offline_sale.sales_amount) AS 'SALES'
FROM   product
       INNER JOIN offline_sale
               ON product.product_id = offline_sale.product_id
GROUP  BY product.product_id
ORDER  BY sales DESC,
          product_code ASC 

/* 몇개가 하나로 묶였는지에 대한 정보는 나오지 않기 때문에 이를 위한 식을 따로 써줘야한다.
SELECT *
FROM PRODUCT INNER JOIN OFFLINE_SALE ON PRODUCT.PRODUCT_ID = OFFLINE_SALE.PRODUCT_ID
GROUP BY PRODUCT.PRODUCT_ID
*/

/* 코드 초안 -> 문제를 꼼꼼히 읽도록 한다.
SELECT 
PRODUCT.PRODUCT_CODE AS PRODUCT_CODE,
SUM(PRODUCT.PRICE * OFFLINE_SALE.SALES_AMOUNT) AS 'SALES'
FROM PRODUCT INNER JOIN OFFLINE_SALE ON PRODUCT.PRODUCT_ID = OFFLINE_SALE.PRODUCT_ID
GROUP BY SUBSTR(PRODUCT.PRODUCT_CODE,1,2)
ORDER BY PRODUCT_CODE
*/