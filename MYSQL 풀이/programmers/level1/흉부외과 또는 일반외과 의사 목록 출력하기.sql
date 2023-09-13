SELECT dr_name,
       dr_id,
       mcdp_cd,
       DATE_FORMAT(hire_ymd, '%Y-%m-%d') AS HIRE_YMD
FROM   doctor
#WHERE MCDP_CD = 'CS' OR MCDP_CD = 'GS'
WHERE  mcdp_cd IN ( 'CS', 'GS' )
ORDER  BY hire_ymd DESC,
          dr_name ASC 
          
# %대문자, 소문자 결과가 다르게 나온다.