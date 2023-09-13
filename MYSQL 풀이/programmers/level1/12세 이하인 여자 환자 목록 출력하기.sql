SELECT pt_name,
       pt_no,
       gend_cd,
       age,
       IF(tlno IS NULL, 'NONE', tlno) AS TLNO
       /*
       CASE
       WHEN TLNO IS NULL THEN 'NONE'
       ELSE TLNO
       END AS TLNO
       */
FROM   patient
WHERE  age <= 12
       AND gend_cd = 'W'
ORDER  BY age DESC,
          pt_name ASC 

#조건이 간단할 때는 IF 복잡하면 CASE를 쓰도록 하자.