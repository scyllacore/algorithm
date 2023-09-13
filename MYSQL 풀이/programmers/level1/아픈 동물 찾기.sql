SELECT animal_id,
       name
FROM   animal_ins
#WHERE INTAKE_CONDITION IN ('Sick')
WHERE  intake_condition = 'Sick'
ORDER  BY animal_id 


#https://doorbw.tistory.com/214
#조건 다음에 정렬이 온다. 순서가 바뀌면 안된다.