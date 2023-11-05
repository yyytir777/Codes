-- 데이터베이스 생성 및 지정
create database IF NOT EXISTS hotel_booking;
use hotel_booking;
alter database hotel_booking default character set utf8mb4;

set foreign_key_checks = 0;    			-- 외래키 체크하지 않는 것으로 설정
drop table IF EXISTS hotel cascade;   				-- 기존 hotel 테이블 제거
drop table IF EXISTS hotelier cascade;   			-- 기존 hotelier 테이블 제거
drop table IF EXISTS hotel_room cascade;   			-- 기존 hotel_room 테이블 제거
drop table IF EXISTS customer cascade;   			-- 기존 customer 테이블 제거
drop table IF EXISTS booking cascade;   			-- 기존 booking 테이블 제거 
drop table IF EXISTS stay_information cascade; 		-- 기존 stay_information 테이블 제거 
drop view IF EXISTS hongik_hotel_customers cascade; -- 기존 hongik_hotel_customers 뷰 제거
set foreign_key_checks = 1;   			-- 외래키 체크하는 것으로 설정


-- (1)  테이블 생성 
create table hotel(
	hid char(4) not null,
    호텔이름 varchar(4),
    호텔주소 varchar(20),
    호텔전화번호 varchar(20),
    primary key (hid)
);

create table hotelier(
	hlid char(5) not null,
    호텔리어이름 char(3),
    hid char(4) not null,
    primary key (hlid),
    foreign key (hid) references hotel(hid)
);

create table hotel_room(
	hid char(4) not null,
	호실 varchar(3) not null,
    가격 int,
    primary key (hid, 호실),
    foreign key (hid) references hotel(hid)
);

create table customer(
	cid char(4) not null,
    고객이름 char(3),
    고객전화번호 varchar(20),
    primary key (cid)
);

create table booking(
	cid char(4) not null,
    hid char(4) not null,
    호실 varchar(3) not null,
    체크인날짜 date,
    체크아웃날짜 date,
    primary key (cid, hid, 호실),
    foreign key (cid) references customer(cid),
    foreign key (hid, 호실) references hotel_room(hid, 호실)
);

create table stay_information(
	cid char(4) not null,
    hid char(4) not null,
    호실 varchar(3) not null,
    체크인날짜 date not null,
    체크아웃날짜 date,
    
    primary key (cid, hid, 호실, 체크인날짜),
	foreign key (cid) references customer(cid),
    foreign key (hid, 호실) references hotel_room(hid, 호실)
);


-- (2)  데이터 삽입

insert into hotel
values ('H001', '홍익호텔', '마포구 상수동', '02-320-1234');
insert into hotel
values ('H002', '중앙호텔', '동작구 흑석동', '02-850-1234');
insert into hotel
values ('H003', '건국호텔', '광진구 자양동', '02-415-1234');


insert into hotelier
values ('HL001', 'KMS', 'H001');
insert into hotelier
values ('HL002', 'LED', 'H001');
insert into hotelier
values ('HL003', 'YHD', 'H002');
insert into hotelier
values ('HL004', 'KKT', 'H002');
insert into hotelier
values ('HL005', 'CPC', 'H003');
insert into hotelier
values ('HL006', 'LSY', 'H003');


insert into hotel_room
values ('H001', '01', 1400);
insert into hotel_room
values ('H001', '02', 1200);
insert into hotel_room
values ('H001', '03', 700);
insert into hotel_room
values ('H002', '01', 1900);
insert into hotel_room
values ('H002', '02', 1000);
insert into hotel_room
values ('H002', '03', 1300);
insert into hotel_room
values ('H002', '04', 1600);
insert into hotel_room
values ('H003', '01', 900);
insert into hotel_room
values ('H003', '02', 1100);


insert into customer
values ('C001', 'PDN', '010-3304-6302');
insert into customer
values ('C002', 'KYS', '010-7323-3789');
insert into customer
values ('C003', 'YDJ', '010-2628-7436');
insert into customer
values ('C004', 'KSM', '010-2299-7827');
insert into customer
values ('C005', 'PJH', '010-3157-2501');
insert into customer
values ('C006', 'HBC', '010-2936-5427');
insert into customer
values ('C007', 'KCY', '010-7119-6732');
insert into customer
values ('C008', 'PYS', '010-2523-9738');


insert into booking
values ('C001', 'H001', '01', '2023/07/16', '2023/07/28');
insert into booking
values ('C002', 'H001', '02', '2023/07/21', '2023/07/22');
insert into booking
values ('C001', 'H002', '01', '2023/08/16', '2023/08/18');
insert into booking
values ('C005', 'H002', '01', '2023/09/06', '2023/09/09');
insert into booking
values ('C005', 'H002', '02', '2023/09/10', '2023/09/18');
insert into booking
values ('C003', 'H002', '02', '2023/09/14', '2023/10/17');
insert into booking
values ('C002', 'H002', '03', '2023/10/16', '2023/10/18');
insert into booking
values ('C008', 'H003', '01', '2023/10/22', '2023/10/26');
insert into booking
values ('C004', 'H003', '01', '2023/10/28', '2023/11/02');
insert into booking
values ('C003', 'H003', '02', '2023/10/29', '2023/11/03');


insert into stay_information
values ('C002', 'H002', '01', '2021/07/16', '2021/07/20');
insert into stay_information
values ('C001', 'H003', '02', '2021/07/21', '2021/07/25');
insert into stay_information
values ('C001', 'H001', '01', '2021/08/16', '2021/08/28');
insert into stay_information
values ('C004', 'H002', '02', '2021/09/06', '2021/09/18');
insert into stay_information
values ('C001', 'H002', '02', '2021/09/10', '2021/09/17');
insert into stay_information
values ('C003', 'H002', '02', '2021/09/14', '2021/09/21');
insert into stay_information
values ('C002', 'H001', '03', '2022/10/15', '2022/10/24');
insert into stay_information
values ('C005', 'H003', '01', '2022/10/19', '2022/10/26');
insert into stay_information
values ('C004', 'H002', '01', '2022/10/22', '2022/10/26');
insert into stay_information
values ('C005', 'H003', '02', '2022/10/29', '2022/11/01');


-- (3) 1)
select "1)";       -- 문제 번호 출력하기
select *
from hotel;

select *
from hotelier;

select *
from hotel_room;

select *
from customer;

select *
from booking
order by 체크인날짜 asc;

select *
from stay_information
order by 체크인날짜 asc;


-- (3) 2)
select "2)";
select hlid, 호텔리어이름
from hotelier
where hid = 'H001';


-- (3) 3)
select "3)";
select cid, hid, sum(datediff(체크아웃날짜, 체크인날짜)) as '투숙 일 수'
from stay_information
group by cid, hid;


-- (3) 4)
select "4)";
select customer.고객이름, hotel.호텔이름
from booking, customer, hotel
where datediff(체크아웃날짜, 체크인날짜) < 4 and booking.cid = customer.cid and booking.hid = hotel.hid;


-- (3) 5)
select "5)";
select sum(datediff(체크아웃날짜, 체크인날짜)) as '총 투숙 일'
from stay_information
where cid = 'C001';


-- (3) 6)
select "6)";
select *
from hotel_room
where 가격 >= 1300
order by hid desc, 호실 asc;


-- (3) 7)
select "7)";
select 호텔이름, 호텔전화번호
from hotel
where hid = (select hid
			 from stay_information
             where 체크인날짜 = (select min(체크인날짜)
							  from stay_information));


-- (3) 8)
select "8)";
select distinct c.고객이름
from booking b, customer c, stay_information si
where c.cid in (select distinct b.cid
				from booking b
				where b.hid = 'H003');


-- (3) 9)
select "9)";
select 호텔이름
from hotel
where hid in (select hid
			  from stay_information
              where date_format(체크인날짜, '%Y') = '2021'
              group by hid having count(*) >= 2);


-- (3) 10)
select "10)";
select 고객이름, 고객전화번호
from customer
where cid in (select si.cid
			  from stay_information si, hotel h, booking b
              where b.hid = h.hid and date_format(si.체크인날짜, '%Y%m%d') < '20220830' and h.호텔주소 like '%흑석동%');
              
              
-- (3) 11)
select "11)";
select 고객이름
from customer c
where exists (select *
			  from booking b
              where c.cid = b.cid and b.hid = 'H001')
              and
	  exists (select *
			  from booking b
              where c.cid = b.cid and b.hid = 'H002');
              
              
-- (3) 12)
select "12)";
select 호텔이름, (select count(*) from booking where booking.hid = hotel.hid) as "총 예약 수",
			(select count(*) from stay_information si where si.hid = hotel.hid) as "총 투숙 수"
from hotel
group by 호텔이름, hid;


-- (3) 13)
select "13)";
update hotel_room
set 가격 = 가격 + 100
where (hid, 호실) in (select hid, 호실
					 from booking
					 where cid = 'C002');

select *
from hotel_room;


-- (3) 14)
select "14)";
delete
from hotelier
where hid = (select hid
			 from hotel
             where 호텔이름 = '중앙호텔');
select *
from hotelier;


-- (3)  15)
select "15)";
create view hongik_hotel_customers
as select	cid, 고객이름, 고객전화번호
   from 	customer
   where 	cid in (select cid
					from stay_information si
                    where hid = 'H001');
select *
from hongik_hotel_customers;


set foreign_key_checks = 0;    			-- 외래키 체크하지 않는 것으로 설정
drop table IF EXISTS hotel cascade;   				-- 기존 hotel 테이블 제거
drop table IF EXISTS hotelier cascade;   			-- 기존 hotelier 테이블 제거
drop table IF EXISTS hotel_room cascade;   			-- 기존 hotel_room 테이블 제거
drop table IF EXISTS customer cascade;   			-- 기존 customer 테이블 제거
drop table IF EXISTS booking cascade;   			-- 기존 booking 테이블 제거 
drop table IF EXISTS stay_information cascade; 		-- 기존 stay_information 테이블 제거 
drop view IF EXISTS hongik_hotel_customers cascade; -- 기존 hongik_hotel_customers 뷰 제거
set foreign_key_checks = 1;   			-- 외래키 체크하는 것으로 설정