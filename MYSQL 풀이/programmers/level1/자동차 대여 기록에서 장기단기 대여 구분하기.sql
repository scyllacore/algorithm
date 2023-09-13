SELECT   history_id,
         car_id,
         DATE_FORMAT (start_date, "%Y-%m-%d") AS start_date,
         DATE_FORMAT (end_date, "%Y-%m-%d")   AS end_date,
         #IF( DATEDIFF(end_date, start_date) < 29,'단기 대여' ,'장기 대여')
         case
                  when datediff(end_date, start_date) < 29 THEN '단기 대여'
                  ELSE '장기 대여'
         end AS rent_type
FROM     car_rental_company_rental_history #where year(start_date) = 2022 AND      month(start_date) = 9
WHERE    start_date LIKE '2022-09-%'
ORDER BY history_id DESC;