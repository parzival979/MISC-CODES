create database if not exists Q2B_Database;
use Q2B_Database;
create table if not exists Employees(employee_id int not null
                                    ,first_name varchar(20) not null
                                    ,last_name varchar(20) not null
                                    ,email varchar(20) not null
                                    ,phone_number varchar(20) not null
                                    ,hire_date varchar(20) not null
                                    ,job_id varchar(10) not null
                                    ,salary int not null
                                    ,manager_id int null
                                    ,department_id int not null);

#Employees entry
insert into Employees(employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, manager_id, department_id) VALUES (700,'Hasmukh','Patel','hp@gmail.com','7003216160','15-aug-2020','Hp003',7000,NULL,90);
insert into Employees(employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, manager_id, department_id) VALUES (800,'Kamlesh','Paul','kp@gmail.com','7003216170','17-feb-2020','Kp 004',8000,506,90);
insert into Employees(employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, manager_id, department_id) VALUES (900,'Dinesh','Gandhi','dp@yahoo','9136278563','19-march-2101','Dg006',20000,508,80);
insert into Employees(employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, manager_id, department_id) VALUES (701,'Suresh','Modi','sm@dg.com','9187653294','20-april-2015','Sm009',15000,NULL,80);

select employee_id,manager_id,first_name,last_name from Employees;