create database if not exists dblab1;

use dblab1;

create table if not exists Student( RollNo char (8), SName varchar (20), Gender char (1), City varchar(20) , primary key(RollNo));
create table if not exists Course (CCode char(5), CName varchar(20), Credit smallint,primary key (CCode));
create table if not exists Enrolled (RollNo char(8)
                                    ,CONSTRAINT RollNo
                                    FOREIGN KEY (RollNo)
                                    references Student(RollNo)
                                    on delete cascade
                                    on UPDATE cascade
                                    ,CCode char(5)
                                    ,constraint CCode
                                    foreign key (CCode)
                                    references Course(CCode)
                                    on delete cascade
                                    on update cascade
                                    ,YoE int);

alter table Course add column Ctype varchar(20);

alter table Student add column Email varchar(30);

insert into Course values ('CS001','psp',3,'core'),
                          ('CS002','dsa',3,'core'),
                          ('CS003','daa',3,'core'),
                          ('ME001','materials',2,'core'),
                          ('ME002','thermodynamics',3,'core'),
                          ('EC001','electrical circuits',3,'core'),
                          ('MA505','probability',3,'elective');

select CName from Course where CCode like 'CS%';

insert into Student values ('2001CS06','sravanth','m','vijayawada','sravanth@gmail.com'),
                           ('2001CS05','sasank','m','vijayawada','sasank@yahoo.com'),
                           ('2001EC44','avinash','m','vijayawada','avi@gmail.com'),
                           ('1901CS99','nischal','m','vijayawada','nis@yahoo.com'),
                           ('2001SM01','avani','f','delhi','avani@gmail.com'),
                           ('2001SM02','avanthi','f','delhi','avanthi@gmail.com');


select SName from Student where SName like '%a%a%' and Gender = 'm';

insert into Enrolled values ('2001CS06','CS001',2018),
                            ('2001CS06','CS002',2019),
                            ('2001CS06','CS003',2020),
                            ('2001CS06','ME002',2019),
                            ('2001CS06','EC001',2020),
                            ('2001CS05','CS001',2018),
                            ('2001CS05','CS002',2019),
                            ('2001CS05','CS003',2020),
                            ('1901CS99','CS001',2018),
                            ('1901CS99','CS002',2019),
                            ('1901CS99','CS003',2020),
                            ('2001EC44','CS001',2020),
                            ('2001EC44','CS002',2020),
                            ('2001EC44','CS003',2020),
                            ('2001EC44','ME001',2020),
                            ('2001EC44','ME002',2020),
                            ('2001EC44','EC001',2020),
                            ('2001SM01','CS001',2020),
                            ('2001SM02','CS001',2020);




select SName from Student where RollNo not in (Select RollNo from Enrolled where YoE  between 2018 and 2019);

select CName from Course where Credit = (select min(Credit) from Course);

select CName from Course where CCode not in (select CCode from Enrolled where YoE = 2020);

select count(City) from Student group by City;

select count(RollNo), RollNo from Enrolled group by RollNo;

select count(CCode) from Enrolled where RollNo = '1901CS99';

select * from Course where CCode like '__5__';

select COUNT(RollNo) from Student where RollNo like '%CS%';

#select RollNo from Enrolled where (select count(RollNo) from Enrolled where YoE = 2020) > 4 ;

#select count(CCode) from Enrolled where RollNo = (select RollNo from Student where Gender = 'f' and City = 'delhi') group by CCode;

select SName from Student where Student.Email like '%gmail.com' or Student.Email like '%yahoo.com';

















