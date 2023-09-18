SELECT car_type,
       COUNT(*) AS 'CARS'  #GROUPING 하고 전체 출력을하면 제일 위에 있는 하나가 대표로 출력된다.
FROM   car_rental_company_car
WHERE  options LIKE '%통풍시트%'
        OR options LIKE '%열선시트%'
        OR options LIKE '%가죽시트%'
GROUP  BY car_type
ORDER  BY car_type ASC 