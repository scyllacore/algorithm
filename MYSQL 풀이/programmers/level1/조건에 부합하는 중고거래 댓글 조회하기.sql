SELECT title,
       used_goods_board.board_id,
       used_goods_reply.reply_id,
       used_goods_reply.writer_id,
       used_goods_reply.contents,
       DATE_FORMAT(used_goods_reply.created_date, '%Y-%m-%d') AS 'CREATED_DATE'
FROM   used_goods_board
       INNER JOIN used_goods_reply
               ON used_goods_board.board_id = used_goods_reply.board_id
WHERE  DATE_FORMAT(used_goods_board.created_date, '%Y-%m') = '2022-10'
ORDER  BY created_date ASC,
          title ASC 