SELECT book.book_id,
       author.author_name,
       DATE_FORMAT(book.published_date, '%Y-%m-%d') AS 'PUBLISHED_DATE' # y m d 의 순서를 바꿔서는 안된다.
FROM   book
       INNER JOIN author
               ON book.author_id = author.author_id
WHERE  category IN ( '경제' )
ORDER  BY published_date ASC 

/*
SELECT BOOK.BOOK_ID, AUTHOR.AUTHOR_NAME, DATE_FORMAT(PUBLISHED_DATE,'%Y-%d-%m') AS 'PUBLISHED_DATE'
FROM BOOK INNER JOIN AUTHOR ON BOOK.AUTHOR_ID = AUTHOR.AUTHOR_ID
WHERE CATEGORY IN ('경제')
ORDER BY PUBLISHED_DATE ASC
*/