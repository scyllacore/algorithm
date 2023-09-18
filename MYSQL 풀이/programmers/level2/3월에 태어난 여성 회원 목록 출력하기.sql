SELECT member_id,
       member_name,
       gender,
       DATE_FORMAT(date_of_birth, '%Y-%m-%d') AS DATE_OF_BIRTH
FROM   member_profile
WHERE  MONTH(date_of_birth) = 3
       AND tlno IS NOT NULL
       AND gender IN ( 'W' ) # = 'W'
ORDER  BY member_id ASC 