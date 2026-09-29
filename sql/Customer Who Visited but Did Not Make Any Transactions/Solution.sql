-- Problem Link : https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/description/


-- Write your PostgreSQL query statement below

SELECT customer_id , COUNT(*) as count_no_trans
FROM Visits as v
LEFT JOIN 
Transactions as t
ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY customer_id;
