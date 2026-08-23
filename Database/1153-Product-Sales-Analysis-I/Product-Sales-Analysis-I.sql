# Write your MySQL query statement below
SELECT product_name , year , price FROM Sales as t1 INNER JOIN Product as t2 ON
t1.product_id = t2.product_id;