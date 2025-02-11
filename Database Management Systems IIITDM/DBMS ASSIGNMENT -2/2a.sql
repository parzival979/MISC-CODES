create database if not exists dblab;

use dblab;

create table Student( Rollno varchar (10), SName varchar (10), City varchar (10));
create table Course (CID varchar(10), CName varchar(10), Credit int(100));

insert into Student values ('CS20B1006','Sravanth','Vijayawada'),
                           ('CS20B1006','Sravanth','Vijayawada'),
                           ('CS20B1006','Sravanth','Vijayawada'),
                           ('CS20B1006','Sravanth','Vijayawada'),
                           ('CS20B1006','Sravanth','Vijayawada'),
                           ('CS20B1006','Sravanth','Vijayawada'),
                           ('CS20B1006','Sravanth','Vijayawada'),
                           ('CS20B1006','Sravanth','Vijayawada'),
                           ('CS20B1006','Sravanth','Vijayawada'),
                           ('CS20B1006','Sravanth','Vijayawada');

insert into Course values ('CS1001','Psp','3'),
                          ('CS1001','Psp','3'),
                          ('CS1001','Psp','3'),
                          ('CS1001','Psp','3'),
                          ('CS1001','Psp','3'),
                          ('CS1001','Psp','3'),
                          ('CS1001','Psp','3'),
                          ('CS1001','Psp','3'),
                          ('CS1001','Psp','3'),
                          ('CS1001','Psp','3');


select * from Course;
select * from Student;

alter table Student add marks int;
alter table Student add department varchar(20);

update Student
set Student.marks = 70;

update Student
set Student.department = 'Mechanical';

alter table Course modify column Credit varchar(100);

alter table Course add Course_admission_date date;

update Course
set dblab.Course.Course_admission_date = '2021-01-24';

select * from Course;
select * from Student;


