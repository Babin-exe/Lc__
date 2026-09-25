-- Problem Link : https://leetcode.com/problems/combine-two-tables/description/


SELECT 
p.firstName , p.lastName ,
a.city , a.state
from Person AS p 
LEFT JOIN Address AS a ON p.personId = a.personId;
