SELECT FIRST_HALF.FLAVOR
FROM FIRST_HALF INNER JOIN ICECREAM_INFO ON FIRST_HALF.FLAVOR = ICECREAM_INFO.FLAVOR
WHERE FIRST_HALF.TOTAL_ORDER >= 3000 AND INGREDIENT_TYPE = 'fruit_based'
ORDER BY FIRST_HALF.TOTAL_ORDER DESC

#https://hongong.hanbit.co.kr/sql-%EA%B8%B0%EB%B3%B8-%EB%AC%B8%EB%B2%95-joininner-outer-cross-self-join/

# https://pearlluck.tistory.com/46

#https://jaimemin.tistory.com/2231

#https://cceeun.tistory.com/189