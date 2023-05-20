# Write your MySQL query statement below
SELECT name AS 'Customers' FROM customers
LEFT JOIN 
orders ON customers.id=orders.customerid
WHERE orders.id IS NULL;