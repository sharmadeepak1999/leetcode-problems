SELECT "Low Salary" AS Category,
SUM(CASE WHEN income<20000 THEN 1 ELSE 0 end) AS accounts_count
FROM Accounts
UNION
SELECT  "Average Salary" Category,
SUM(CASE WHEN income >= 20000 AND income <= 50000 THEN 1 ELSE 0 END) AS accounts_count
FROM Accounts
UNION
SELECT "High Salary" category,
SUM(CASE WHEN income>50000 THEN 1 ELSE 0 END) AS accounts_count
FROM Accounts
