select decode(gen, 'M', '남학생', '여학생') 성별, round(avg(grade),2) 평균성적
from student
group by gen;

select deptno, avg(grade)
from student
where deptno in (10, 30)
group by deptno;

select deptno, avg(grade)
from student
group by deptno
having avg(grade) >= 3.0;

select sid, sname, deptno
from student
where deptno in (select deptno from department where budget >= 10000000)
order by deptno;

select sid, sname, deptno
from student
where deptno = (select deptno from department where dname = 'Computer');

select sdi, sname, sid
from student
where dname = (select dname
								from department
								where deptno = 10);
                                
select sid, sname, grade
from student
where grade > (select grade from student where sid=1007);

select sname, grade, deptno
from student
where grade > (select min(grade) from student where deptno = 40);

select sid, sname, grade
from student
where gen = 'M' and grade >= all (select grade from student where gen = 'M');

select sid, sname, grade
from student
where gen = 'M'
and grade = (select max(grade)
									from student
									where gen = 'M');

select sid, sname, grade
from student
where gen = 'M'
and grade >all (select grade
									from student
									where gen = 'M');
                                    

select deptno, avg(grade)
from student
group by deptno
having avg(grade) in (select max(avg(grade)) from student group by deptno);
/*학점이 가장 높은 학생이 재학중인 학과 이름*/
select dname
from department d
where EXISTS (select sid from student where deptno = d.deptno and grade = (
select max(grade) from student));

