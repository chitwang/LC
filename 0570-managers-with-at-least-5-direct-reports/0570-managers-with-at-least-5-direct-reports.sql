# Write your MySQL query statement below
SELECT e1.name FROM Employee as e1
    WHERE e1.id in (
        SELECT e2.managerId FROM Employee as e2
            GROUP BY e2.managerId
                HAVING COUNT(*) >= 5
    );