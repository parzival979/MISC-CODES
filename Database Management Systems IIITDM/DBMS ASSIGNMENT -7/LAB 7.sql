create database lab7;
use lab7;
create table Bank(Bank_name varchar(10)
                 ,State varchar(25));
create table Account_holder(Account_name varchar(25)
                           ,Bank_name varchar(25)
                           ,State_name varchar(25));

insert into Bank values ('SBI','ANDHRA PRADESH'),
                        ('SBI','TAMIL NADU'),
                        ('SBI','KARNATAKA'),
                        ('ICICI','TAMIL NADU'),
                        ('ICICI','KARNATAKA');

insert into Account_holder values ('RAMESH','ICICI','TAMIL NADU'),
                                  ('DINESH','SBI','ANDHRA PRADESH'),
                                  ('ROBERT','SBI','TAMIL NADU'),
                                  ('ROBERT','ICICI','KARNATAKA'),
                                  ('ROBERT','SBI','ANDHRA PRADESH'),
                                  ('KARTHIK','SBI','ANDHRA PRADESH');


CREATE TABLE AllBANKS AS SELECT DISTINCT BANK_NAME FROM Bank;
CREATE TABLE NAMES AS SELECT DISTINCT Account_name FROM Account_holder;
CREATE table reqNamesAndBanks AS SELECT * FROM AllBANKS CROSS JOIN NAMES;
select * from reqNamesAndBanks;
create table notholders as select * from reqNamesAndBanks where not exists(select * from Account_holder where reqNamesAndBanks.BANK_NAME=Account_holder.Bank_name and reqNamesAndBanks.Account_name=Account_holder.Account_name);
select * from notholders;
create table 1ans as select * from NAMES where not exists(select * from notholders where notholders.Account_name=NAMES.Account_name);
select * from 1ans;

create table states as select distinct State from Bank;
CREATE table statesandbanks AS SELECT * FROM AllBANKS CROSS JOIN states;
select * from statesandbanks;
create table notallstates as select * from statesandbanks where not exists(select * from Bank where statesandbanks.BANK_NAME=Bank.Bank_name and statesandbanks.State=Bank.State);
select * from notallstates;
create table 2ans as select * from AllBANKS where not exists(select * from notallstates where notallstates.BANK_NAME=AllBANKS.BANK_NAME);
select * from 2ans;

select BANK_NAME from notallstates;



CREATE table reqNamesAndstates AS SELECT * FROM states CROSS JOIN NAMES;
select * from reqNamesAndstates;
create table notholdersstates as select * from reqNamesAndstates where not exists(select * from Account_holder where reqNamesAndstates.State=Account_holder.State_name and reqNamesAndstates.Account_name=Account_holder.Account_name);
select * from notholdersstates;
create table 4ans as select * from NAMES where not exists(select * from notholdersstates where notholdersstates.Account_name=NAMES.Account_name);
select * from 4ans;



