create database if not exists Q5B_DATABASE;
USE Q5B_DATABASE;

create table if not exists salesman(Salesman_id varchar(20) not null
                                   ,Name varchar(30) not null
                                   , City varchar(20) not null
                                   , commission float
);

create table if not exists orders(ord_no int not null
                                 ,Purch_amt int not null
                                 ,Ord_date varchar(20) not null
                                 ,Customer_id varchar(20) not null
                                 ,Salesman_id varchar(20) not null );

insert into salesman values('si123@06','Lakshmi','Kolkata',0.5),
                            ('si123@09','Ganesh','London',0.6),
                           ('si123@90','Dinesh','London',0.3),
                           ('si123@10','Joseph','Chennai',0.6),
                           ('si123@19','Mahesh','Hyderabad',0.65),
                           ('si123@26','Paul Adam','London',0.1),
                           ('si123@67','Rahul','Delhi',0.4);

insert into orders values (123,600,'20-aug-2010','003cd','si123@19'),
                          (576,750,'20-feb-2018','004cd','si123@19'),
                          (579,800,'20-may-2012','004cd','si123@26'),
                          (600,60000,'20-jan-2021','006cd','si123@10'),
                          (700,745,'26-jan-2021','007cd','si123@09'),
                          (800,860,'29-jan-2019','007cd','si123@26');

select * from orders where Salesman_id = (select Salesman_id from salesman where Name = 'Paul Adam');

select * from orders where Salesman_id in (select Salesman_id from salesman where City = 'London');


