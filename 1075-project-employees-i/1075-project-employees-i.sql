# Write your MySQL query statement below
select 
    project_id,
    Round(AVG(Employee.experience_years), 2) as average_years
    from Project, Employee
    where Project.employee_id = Employee.employee_id
    group by project_id;