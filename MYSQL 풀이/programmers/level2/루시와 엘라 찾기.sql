SELECT animal_id,
       name,
       sex_upon_intake
FROM   animal_ins
WHERE  name IN ( 'Lucy', 'Ella', 'Pickle', 'Rogan',
                 'Sabrina', 'Mitty' )
ORDER  BY animal_id 

#https://jione-e.tistory.com/73
#WHERE NAME = 'Lucy' OR NAME = 'Ella' OR NAME = 'Pickle' OR NAME = 'Rogan' OR NAME = 'Sabrina' OR NAME = 'Mitty'