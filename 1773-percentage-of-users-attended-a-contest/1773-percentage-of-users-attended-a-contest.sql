# Write your MySQL query statement below
SELECT contest_id, ROUND(100 * COUNT(r.user_id)/(SELECT COUNT(user_id) FROM Users), 2) as percentage 
    FROM Register as r
    GROUP BY contest_id
    ORDER BY percentage DESC, contest_id ASC;