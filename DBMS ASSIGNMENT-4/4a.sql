create database if not exists Assignment_4;

use Assignment_4;

create table STUDENTACCOUNT(id int
                           ,Person_name varchar(20)
                           ,Department varchar(10)
                           ,DOB date);

insert into STUDENTACCOUNT(id,person_name, department, dob) VALUES (1,'Ramesh','Cs','2001-01-12'),
                                                                (2,'suresh','IT','2020-02-20'),
                                                                (3,'Jomin','IT','1996-02-26'),
                                                                (4,'Shree','IT','2012-12-18'),
                                                                (5,'Hemanth','CS','2022-02-07');

select Person_name,dob,CONCAT(FLOOR((TIMESTAMPDIFF(MONTH, dob, CURDATE()) / 12)), ' YEARS ',MOD(TIMESTAMPDIFF(MONTH, dob, CURDATE()), 12) , ' MONTHS') AS age from STUDENTACCOUNT;

select * from STUDENTACCOUNT where Person_name like '%s%';

select * from STUDENTACCOUNT where Person_name like '_____' ;

select id,Department from STUDENTACCOUNT;

select Person_name,DOB from STUDENTACCOUNT;

