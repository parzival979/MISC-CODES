create database if not exists IIIT;
use IIIT;
create table if not exists IIITDM(Faculty_name varchar(30) NULL,
                                  Student_id varchar(10) NULL,
                                  Subject varchar(20) NULL );
create table if not exists Faculty(FacultyId varchar(10) NOT NULL,
                                  Faculty_name varchar(30) NOT NULL,
                                   department varchar(10) NOT NULL,
                                    subject varchar(30) NOT NULL);
create table if not exists Student(student_id varchar(10) NOT NULL
                                  ,Student_name varchar(30) NOT NULL
                                  ,course varchar(20) not null
                                  ,building_name varchar(30) not null
                                  );
create table if not exists Building(building_name varchar(30) not null
                                   ,room_no MEDIUMINT not null
                                   ,Floor smallint not null );
create table if not exists Course (department varchar(20) not null
                                  , subject varchar(20) not null
                                  , course_id varchar(10) not null );
#IIITDM entry
insert into IIITDM(faculty_name, student_id, subject) values('Dr Jagadeesh Kakarla','Sravanth','DBMS');
insert into IIITDM(faculty_name, student_id, subject) values('Dr Jagadeesh Kakarla','Sravanth','DBMS');
insert into IIITDM(faculty_name, student_id, subject) values('Dr Jagadeesh Kakarla','Sravanth','DBMS');
insert into IIITDM(faculty_name, student_id, subject) values('Dr Jagadeesh Kakarla','Sravanth','DBMS');
insert into IIITDM(faculty_name, student_id, subject) values('Dr Jagadeesh Kakarla','Sravanth','DBMS');
insert into IIITDM(faculty_name, student_id, subject) values('Dr Jagadeesh Kakarla','Sravanth','DBMS');
insert into IIITDM(faculty_name, student_id, subject) values('Dr Jagadeesh Kakarla','Sravanth','DBMS');
insert into IIITDM(faculty_name, student_id, subject) values('Dr Jagadeesh Kakarla','Sravanth','DBMS');
insert into IIITDM(faculty_name, student_id, subject) values('Dr Jagadeesh Kakarla','Sravanth','DBMS');
insert into IIITDM(faculty_name, student_id, subject) values('Dr Jagadeesh Kakarla','Sravanth','DBMS');

#Faculty entry
insert into Faculty(facultyid, faculty_name, department, subject) values ('JK18','Dr Jagadeesh Kakarla','CS','DBMS');
insert into Faculty(facultyid, faculty_name, department, subject) values ('JK18','Dr Jagadeesh Kakarla','CS','DBMS');
insert into Faculty(facultyid, faculty_name, department, subject) values ('JK18','Dr Jagadeesh Kakarla','CS','DBMS');
insert into Faculty(facultyid, faculty_name, department, subject) values ('JK18','Dr Jagadeesh Kakarla','CS','DBMS');
insert into Faculty(facultyid, faculty_name, department, subject) values ('JK18','Dr Jagadeesh Kakarla','CS','DBMS');
insert into Faculty(facultyid, faculty_name, department, subject) values ('JK18','Dr Jagadeesh Kakarla','CS','DBMS');
insert into Faculty(facultyid, faculty_name, department, subject) values ('JK18','Dr Jagadeesh Kakarla','CS','DBMS');
insert into Faculty(facultyid, faculty_name, department, subject) values ('JK18','Dr Jagadeesh Kakarla','CS','DBMS');
insert into Faculty(facultyid, faculty_name, department, subject) values ('JK18','Dr Jagadeesh Kakarla','CS','DBMS');
insert into Faculty(facultyid, faculty_name, department, subject) values ('JK18','Dr Jagadeesh Kakarla','CS','DBMS');

#Student Entry
insert into Student(student_id, Student_name, course, building_name) values ('CS20B1006','Sravanth','DBMS','Main');
insert into Student(student_id, Student_name, course, building_name) values ('CS20B1006','Sravanth','DBMS','Main');
insert into Student(student_id, Student_name, course, building_name) values ('CS20B1006','Sravanth','DBMS','Main');
insert into Student(student_id, Student_name, course, building_name) values ('CS20B1006','Sravanth','DBMS','Main');
insert into Student(student_id, Student_name, course, building_name) values ('CS20B1006','Sravanth','DBMS','Main');
insert into Student(student_id, Student_name, course, building_name) values ('CS20B1006','Sravanth','DBMS','Main');
insert into Student(student_id, Student_name, course, building_name) values ('CS20B1006','Sravanth','DBMS','Main');
insert into Student(student_id, Student_name, course, building_name) values ('CS20B1006','Sravanth','DBMS','Main');
insert into Student(student_id, Student_name, course, building_name) values ('CS20B1006','Sravanth','DBMS','Main');
insert into Student(student_id, Student_name, course, building_name) values ('CS20B1006','Sravanth','DBMS','Main');

#Building Entry
insert into Building(building_name, room_no, Floor) values('Main',128,2);
insert into Building(building_name, room_no, Floor) values('Main',128,2);
insert into Building(building_name, room_no, Floor) values('Main',128,2);
insert into Building(building_name, room_no, Floor) values('Main',128,2);
insert into Building(building_name, room_no, Floor) values('Main',128,2);
insert into Building(building_name, room_no, Floor) values('Main',128,2);
insert into Building(building_name, room_no, Floor) values('Main',128,2);
insert into Building(building_name, room_no, Floor) values('Main',128,2);
insert into Building(building_name, room_no, Floor) values('Main',128,2);
insert into Building(building_name, room_no, Floor) values('Main',128,2);

#Course Entry
insert into Course(department, subject, course_id) values ('CSE','DBMS','CS1004');
insert into Course(department, subject, course_id) values ('CSE','DBMS','CS1004');
insert into Course(department, subject, course_id) values ('CSE','DBMS','CS1004');
insert into Course(department, subject, course_id) values ('CSE','DBMS','CS1004');
insert into Course(department, subject, course_id) values ('CSE','DBMS','CS1004');
insert into Course(department, subject, course_id) values ('CSE','DBMS','CS1004');
insert into Course(department, subject, course_id) values ('CSE','DBMS','CS1004');
insert into Course(department, subject, course_id) values ('CSE','DBMS','CS1004');
insert into Course(department, subject, course_id) values ('CSE','DBMS','CS1004');
insert into Course(department, subject, course_id) values ('CSE','DBMS','CS1004');

select * from Student;
select * from Course;
select * from Building;
select * from Faculty;
select * from IIITDM;


