-- This Program is done by CS20B1006 SRAVANTH CHOWDARY POTLURI
CREATE DATABASE lab6;
USE lab6;

-- Creation of tables
CREATE TABLE IIITDM (
                        Faculty_name varchar(10),
                        Student_id varchar(10),
                        Building_name varchar(15)
);

CREATE TABLE Faculty (
                         Faculty_id varchar(10),
                         Faculty_name varchar(20),
                         department varchar(20),
                         subject varchar(20),
                         PRIMARY KEY (Faculty_id)
);

CREATE TABLE Student (
                         Student_id varchar(10),
                         Student_name varchar(20),
                         department varchar(20),
                         course_id varchar(5),
                         Building_name varchar(15),
                         Room_no varchar(4),
                         PRIMARY KEY (Student_id)
);

CREATE TABLE Building (
                          Building_name varchar(15),
                          Room_no varchar(4),
                          Floor int
);

CREATE TABLE Course (
                        department varchar(20),
                        subject varchar(20),
                        course_id varchar(5)
);

-- Insertion of values into tables
INSERT INTO iiitdm
VALUES('Jagadeesh','CS20B1006','Ashoka');
INSERT INTO iiitdm
VALUES('Sadgopan','COE19B1069','Ashwatha');
INSERT INTO iiitdm
VALUES('Shalu','CS20B1100','Ashwatha');
INSERT INTO iiitdm
VALUES('Bingi','CS20B1056','Banyan');
INSERT INTO iiitdm
VALUES('Rahul','EC21B1050','Jasmine');


INSERT INTO faculty
VALUES('F1','Jagadeesh','CSE','DBMS');
INSERT INTO faculty
VALUES('F2','Sadgopan','CSE','TOC');
INSERT INTO faculty
VALUES('F3','Shalu','Math','Probability');
INSERT INTO faculty
VALUES('F4','Bingi','Design','SPD');
INSERT INTO faculty
VALUES('F5','Rahul','CSE','DLD');

INSERT INTO student
VALUES('CS20B1006','Sravanth','CSE','CS208','Ashoka','30');
INSERT INTO student
VALUES('COE19B1069','Amit','CSE','CS209','Ashwatha','140');
INSERT INTO student
VALUES('CS20B1100','Sam','CSE','MA202','Ashwatha','304');
INSERT INTO student
VALUES('CS20B1056','Bekar','CSE','DS202','Banyan','420');
INSERT INTO student
VALUES('EC21B1050','Priya','ECE','EC204','Jasmine','500');

INSERT INTO building
VALUES('Ashoka','30',3);
INSERT INTO building
VALUES('Ashwatha','140',5);
INSERT INTO building
VALUES('Ashwatha','304',3);
INSERT INTO building
VALUES('Banyan','420',4);
INSERT INTO building
VALUES('Jasmine','500',5);

INSERT INTO course
VALUES('CSE','DBMS','CS208');
INSERT INTO course
VALUES('CSE','TOC','CS209');
INSERT INTO course
VALUES('Math','Probability','MA202');
INSERT INTO course
VALUES('Design','SPD','DS202');
INSERT INTO course
VALUES('CSE','DLD','EC204');

-- QUERY 1
SELECT student.student_id FROM student WHERE student.Room_no = '30' AND course_id IN (SELECT course_id FROM Course INNER JOIN faculty ON faculty.subject = course.subject);

-- QUERY 2
SELECT student.course_id FROM Student WHERE student.Building_name IN (SELECT Building_name FROM building WHERE Building_name = 'Ashwatha' AND Room_no = '140' AND student.Room_no = Room_no);

-- QUERY 3
SELECT * FROM faculty WHERE subject NOT IN (SELECT subject FROM course INNER JOIN student ON course.course_id = student.course_id AND student.student_id = 'CS20B1006');

-- QUERY 4
SELECT student.course_id FROM Student WHERE student.room_no IN (SELECT room_no FROM building WHERE Building.Floor = 3 AND Building_name = 'Ashwatha');