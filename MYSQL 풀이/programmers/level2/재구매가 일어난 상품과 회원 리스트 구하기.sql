SELECT user_id,
       product_id #,COUNT(*)
FROM   online_sale
GROUP  BY user_id,
          product_id
HAVING COUNT(*) >= 2
ORDER  BY user_id ASC,
          product_id DESC 

#https://www.inflearn.com/questions/27971/group-by%EC%97%90-%EB%91%90-%EA%B0%9C-%EC%9D%B4%EC%83%81%EC%9D%98-column%EC%9D%84-%EC%93%B0%EB%8A%94-%EA%B2%BD%EC%9A%B0