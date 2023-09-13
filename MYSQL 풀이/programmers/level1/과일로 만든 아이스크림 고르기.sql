SELECT first_half.flavor
FROM   first_half
       INNER JOIN icecream_info
               ON first_half.flavor = icecream_info.flavor
#WHERE FIRST_HALF.TOTAL_ORDER >= 3000 AND INGREDIENT_TYPE = 'fruit_based'
#중복이 되는 속성명이 아니라면 테이블을 따로 언급할 필요 없다.
WHERE  total_order >= 3000
       AND ingredient_type = 'fruit_based'
ORDER  BY total_order DESC 

#https://hongong.hanbit.co.kr/sql-%EA%B8%B0%EB%B3%B8-%EB%AC%B8%EB%B2%95-joininner-outer-cross-self-join/

#https://pearlluck.tistory.com/46

#https://jaimemin.tistory.com/2231

#https://cceeun.tistory.com/189