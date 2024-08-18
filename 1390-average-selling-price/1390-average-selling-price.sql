# Write your MySQL query statement below
SELECT Prices.product_id, IFNULL(ROUND(SUM(Prices.price * UnitsSold.units)/SUM(UnitsSold.units), 2), 0) as average_price FROM
    Prices LEFT JOIN UnitsSold ON (UnitsSold.product_id = Prices.product_id AND UnitsSold.purchase_date BETWEEN Prices.start_date AND Prices.end_date)
        GROUP BY Prices.product_id;  