SELECT COUNT(*) AS USERS
FROM   user_info
WHERE  age IS NULL 

#WHERE은 원하는 튜플만 선택
#IF,CASE는 튜플의 속성값에 변화를 줌