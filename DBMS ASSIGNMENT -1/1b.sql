create database if not exists Q1B_DATABASE;
use Q1B_DATABASE;
create table if not exists Agent(Agent_Code varchar(10) NOT NULL
                                ,Agent_name varchar(30) not null
                                ,Working_area varchar(20) not null
                                ,Commission float(5,3) not null
                                ,Phone_no varchar(15) not null
                                ,Country varchar(20) null );

create table if not exists Orders(Ord_num int not null
                                 ,ord_amount int not null
                                 ,Advance_amount int not null
                                 ,ord_date varchar(20) not null
                                 ,Cust_code varchar(10) not null
                                 ,Agent_code varchar(10) not null
                                 ,Description varchar(30) not null);
#Orders Entry

insert into Orders(ord_num, ord_amount, advance_amount, ord_date, cust_code, agent_code, description) VALUES (004,200,300,'15-aug-2000','C004','AC001','Masala kulcha');
insert into Orders(ord_num, ord_amount, advance_amount, ord_date, cust_code, agent_code, description) VALUES (007,600,5000,'17-sep-2020','C006','Ac003','Biryani');
insert into Orders(ord_num, ord_amount, advance_amount, ord_date, cust_code, agent_code, description) VALUES (008,700,100,'19-feb-2019','C007','Ac005','Biryani');
insert into Orders(ord_num, ord_amount, advance_amount, ord_date, cust_code, agent_code, description) VALUES (009,10000,600,'21-march-2010','C009','Ac002','Masala Dosa');
insert into Orders(ord_num, ord_amount, advance_amount, ord_date, cust_code, agent_code, description) VALUES (010,20,600,'21-apr-2012','C006','Ac005','Chicken Tikka');

# Agent Entry
insert into Agent(agent_code, agent_name, working_area, commission, phone_no, Country) VALUES ('ACc001','Ramesh','Bangalore',0.15,'0331234567','india');
insert into Agent(agent_code, agent_name, working_area, commission, phone_no) VALUES ('Ac002','Dinesh','Bangalore',0.25,'0331234568');
insert into Agent(agent_code, agent_name, working_area, commission, phone_no,Country) Values ('Ac003','Suresh','Mumbai',0.35,'0331234569','London');
insert into Agent(agent_code, agent_name, working_area, commission, phone_no) VALUES ('Ac004','Kamlesh','New Jersey',0.68,'0331234564');
insert into Agent(agent_code, agent_name, working_area, commission, phone_no, country) VALUES ('Ac005','Kartik','Chennai',0.73,'0331234563','India');

#Tables Display
select * from Orders;
select * from Agent;