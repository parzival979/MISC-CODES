create database if not exists IIITDM;

use IIITDM;

create table Student(student_id varchar(10)
                    ,first_name varchar(20)
                    ,last_name varchar(20)
                    ,parent_name varchar(40)
                    ,age int
                    );

create table Faculty(faculty_id varchar(10)
                    ,name varchar(40)
                    ,age int
                    ,department varchar(30)
                    ,date_of_joining date
                    );

create table Building(building_name varchar(20)
                     ,building_id varchar(10)
                     ,capacity_of_students int
                     ,no_of_floors int
                     ,date_of_inauguration date
                     );



insert into Student values ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18);

insert into Faculty values ('djk100','DR Jagadeesh Kakarla',40,'CSE','2019-11-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2019-11-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2019-11-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2019-11-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2019-11-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2019-11-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2019-11-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2019-11-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2019-11-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2019-11-11');

insert into Building values ('Main','Main2301',1000,5,'2015-05-26'),
                            ('Main','Main2301',1000,5,'2015-05-26'),
                            ('Main','Main2301',1000,5,'2015-05-26'),
                            ('Main','Main2301',1000,5,'2015-05-26'),
                            ('Main','Main2301',1000,5,'2015-05-26'),
                            ('Main','Main2301',1000,5,'2015-05-26'),
                            ('Main','Main2301',1000,5,'2015-05-26'),
                            ('Main','Main2301',1000,5,'2015-05-26'),
                            ('Main','Main2301',1000,5,'2015-05-26'),
                            ('Main','Main2301',1000,5,'2015-05-26');

select * from Building;
select * from Faculty;
select * from Student;

insert into Faculty values ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11');

insert into Student values ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18);

insert into Building values ('Main','Main2301',1000,5,'2016-01-26'),
                            ('Main','Main2301',1000,5,'2016-01-26'),
                            ('Main','Main2302',1000,5,'2016-01-26');

select * from Building;
select * from Faculty;
select * from Student;

alter table Student add column department varchar(20);

insert into Student values ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE'),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE'),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'Mechanical'),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'Mechanical'),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'Mechanical');

insert into Faculty values ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'CSE','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'Electrical','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'Electrical','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'Electrical','2020-05-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'Electrical','2020-05-11');

select * from Student;
select * from Faculty;


insert into Faculty values ('djk100','DR Jagadeesh Kakarla',40,'Electrical','2020-08-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'Electrical','2020-08-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'Electrical','2020-08-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'Electrical','2020-08-11'),
                           ('djk100','DR Jagadeesh Kakarla',40,'Electrical','2020-08-11');

insert into Student values ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'Math'),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'Math'),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'Physics');

select * from Faculty;
select * from Student;

delete from Building where building_id = 'Main2302';

select * from Building;

alter table Student add column mark_percent float;

insert into Student values ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE',99.5),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE',99.5),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE',99.5),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE',99.5),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE',99.5),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE',99.5),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE',99.5),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE',99.5),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE',99.5),
                           ('CS20B1006','SRAVANTH','POTLURI','NAVEEN POTLURI',18,'CSE',99.5);

select * from Student;

alter table Building drop column date_of_inauguration;
alter table Building add column staff_id varchar(10);

select * from Building;










