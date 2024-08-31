WITH r1
     AS (SELECT Max(views) AS 'MAX_VIEW'
         FROM   used_goods_board),
     r2
     AS (SELECT board_id
         FROM   used_goods_board
                INNER JOIN r1
                        ON used_goods_board.views = r1.max_view),
     r3
     AS (SELECT FILE.board_id AS 'BOARD_ID',
                file_id,
                file_name,
                file_ext
         FROM   used_goods_file AS FILE
                INNER JOIN r2
                        ON FILE.board_id = r2.board_id)
                        
SELECT CONCAT('/home/grep/src/', board_id, '/', file_id, file_name, file_ext) AS
       'FILE_PATH'
FROM   r3
ORDER  BY file_id DESC 