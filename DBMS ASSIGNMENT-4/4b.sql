create database if not exists Assignment_4;

use Assignment_4;

create table Employees(id int not null primary key, FirstName varchar(15) not null,LastName varchar(15) not null,Salary bigint not null, JoiningDate date not null, Department varchar(10));

insert into Employees values(1,'Boby','Rathod',1000000, '2020-12-20','Finance');
insert into Employees values(2,'Jasmin','Jose',6000000, '2015-02-07','IT');
insert into Employees values(3,'Pratap','Mathew',8900000, '2014-03-09','Banking');
insert into Employees values(4,'John','Michel',2000000, '1999-03-17','Insurance');
insert into Employees values(5,'Alex','Kinto',2200000, '1987-02-25','Finance');
insert into Employees values(6,'Jashwanth','Kumar',1230000, '2021-07-23','IT');

select * from Employees where Salary between 2000000 and 5000000;

select LastName from Employees where timestampdiff(year , JoiningDate,curdate())>=3 and FirstName like '%a%';

select JoiningDate from Employees where Salary > (select avg(Salary) from Employees);

select * from Employees where Salary < (select avg(Salary) from Employees where Department = 'IT') and Department = 'Finance';
