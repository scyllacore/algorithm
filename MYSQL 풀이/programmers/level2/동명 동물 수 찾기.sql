SELECT name,
       COUNT(name) AS COUNT
FROM   animal_ins
GROUP  BY name
HAVING COUNT(name) >= 2
ORDER  BY name 

# https://wansook0316.github.io/cs/database/2020/04/25/where-having-%EC%B0%A8%EC%9D%B4.htmls

# https://velog.io/@petit-prince/MySQL-%EB%AC%B8%EB%B2%95-COUNT-%EC%99%80-COUNTColName%EC%9D%98-%EC%B0%A8%EC%9D%B4