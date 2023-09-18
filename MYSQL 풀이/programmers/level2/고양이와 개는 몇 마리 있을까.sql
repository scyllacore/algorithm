SELECT animal_type,
       COUNT(animal_type) AS 'count'
FROM   animal_ins
GROUP  BY animal_type
ORDER  BY animal_type

#COUNT(CASE WHEN ... THEN END)

#COUNT안에 컬럼을 넣어주면 NULL값을 제외하고 찾고 *로 처리하면 NULL값을 포함하여 모든 행 개수를 반환.

#https://kimsyoung.tistory.com/entry/SQL-GROUP-BY-%E4%B8%8A-%EA%B0%9C%EB%85%90%EA%B3%BC-%EC%8B%A4%EC%A0%9C-%EC%A0%81%EC%9A%A9-%EB%B0%A9%EB%B2%95