SELECT mcdp_cd  AS '진료과코드',
       COUNT(*) AS '5월예약건수'
FROM   appointment
WHERE  apnt_ymd LIKE '2022-05%'  #YEAR(APNT_YMD) = 2022 AND MONTH(APNT_YMD) = 5
GROUP  BY mcdp_cd
ORDER  BY 5월예약건수 ASC,
          진료과코드 ASC 
         
    