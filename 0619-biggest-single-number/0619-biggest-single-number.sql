# Write your MySQL query statement below
SELECT MAX(num) as num FROM MyNumbers as mn1
    WHERE num IN (SELECT num as n1 FROM MyNumbers as mn2 
                    GROUP BY n1
                        HAVING COUNT(n1) = 1
                );