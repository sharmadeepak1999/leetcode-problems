# Write your MySQL query statement below
select name, bonus from Employee left join Bonus using(empId) where bonus < 1000 OR bonus is null;