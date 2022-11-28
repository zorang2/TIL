select *
from department;

select sname, deptno, grade
from student
where grade >= 3.5 and gen = "F";

select sname, deptno, grade
from student
where grade >= 3.5 and gen = 'F';

select budget
from department
where dname = 'Computer';

select *
from professor;