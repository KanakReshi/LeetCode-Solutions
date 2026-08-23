# Write your MySQL query statement below
SELECT t2.id as id FROM Weather as t1 INNER JOIN Weather as t2 ON t1.recordDate = t2.recordDate - INTERVAL 1 DAY
WHERE t2.temperature > t1.temperature;