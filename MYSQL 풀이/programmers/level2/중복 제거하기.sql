SELECT CAT_ANIMAL_INS.ANIMAL_TYPE
FROM 
    (
        SELECT * 
        FROM ANIMAL_INS
        WHERE ANIMAL_TYPE = 'CAT'
    ) CAT_ANIMAL_INS
    INNER JOIN
    (
        SELECT * 
        FROM ANIMAL_INS
        WHERE ANIMAL_TYPE = 'DOG'
    ) DOG_ANIMAL_INS
WHERE CAT_ANIMAL_INS.NAME = 'Ella' AND DOG_ANIMAL_INS.NAME = 'Bj'

    
    
# https://chanhuiseok.github.io/posts/db-4/