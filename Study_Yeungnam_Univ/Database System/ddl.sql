create table DEPARTMENT (
	deptno number(2) not null primary key, 
	dname varchar2(20), 
	college varchar2(20), 
	budget number(8)
); 

create table PROFESSOR (
	pid number(3) not null primary key, 
	pname varchar2(10), 
	deptno number(2) references DEPARTMENT(deptno), 
	major varchar2(10), 
	hiredate date
);

create table STUDENT (
	sid number(4) not null primary key, 
	sname varchar2(10), 
	deptno number(2) references DEPARTMENT(deptno), 
	advisor number(3) references PROFESSOR(pid),
	gen varchar2(2),
	addr varchar2(10), 
	birthdate date, 
	grade number(3,2) check (grade between 0.0 and 4.5)
);