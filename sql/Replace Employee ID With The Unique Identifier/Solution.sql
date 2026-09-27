
-- Problem Link : https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/description/

SELECT e.unique_id, ee.name
FROM Employees ee
LEFT JOIN EmployeeUNI e
    ON e.id = ee.id;
