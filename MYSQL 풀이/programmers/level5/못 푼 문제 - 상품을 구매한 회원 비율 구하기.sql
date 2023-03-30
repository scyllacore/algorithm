WITH R1 AS(
    SELECT
        *
    FROM
        USER_INFO
    WHERE
        JOINED LIKE '2021%'
),
MEMBER_COUNT AS(
    SELECT
        COUNT(*) AS 'TOTAL_MEMBER'
    FROM
        R1
),
R2 AS(
    SELECT
        ONLINE_SALE.ONLINE_SALE_ID
        ,ONLINE_SALE.USER_ID	
        ,ONLINE_SALE.PRODUCT_ID
        ,ONLINE_SALE.SALES_DATE
    FROM
        R1
        INNER JOIN
        ONLINE_SALE
            ON R1.USER_ID = ONLINE_SALE.USER_ID
    ORDER BY
        ONLINE_SALE.PRODUCT_ID
),
R3 AS(
    SELECT
        PRODUCT_ID    
        ,COUNT(PRODUCT_ID) AS 'COUNT'
    FROM
        R2
    GROUP BY
        PRODUCT_ID
        
)

SELECT 
    *
FROM
    R2