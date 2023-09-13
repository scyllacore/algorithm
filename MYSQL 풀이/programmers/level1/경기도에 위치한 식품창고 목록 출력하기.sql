SELECT warehouse_id,
       warehouse_name,
       address,
       IF(freezer_yn IS NULL, 'N', freezer_yn) AS FREEZER_YN
        /*
        CASE # IF나 CASE는 FROM전에 쓴다.
            WHEN FREEZER_YN IS NULL THEN 'N'
            ELSE FREEZER_YN #붙어야함
        END AS FREEZER_YN
        */    
FROM   food_warehouse
WHERE  address LIKE '경기도%'
ORDER  BY warehouse_id ASC 


#https://velog.io/@zinu/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B2%BD%EA%B8%B0%EB%8F%84%EC%97%90-%EC%9C%84%EC%B9%98%ED%95%9C-%EC%8B%9D%ED%92%88%EC%B0%BD%EA%B3%A0-%EB%AA%A9%EB%A1%9D-%EC%B6%9C%EB%A0%A5%ED%95%98%EA%B8%B0MySQLIFNULLCASE-WHEN