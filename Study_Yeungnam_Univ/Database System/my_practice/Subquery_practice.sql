/*
학점이 가장 높은 학생의 이름과 학과, 학점을 출력
*/
SELECT sname, deptno, grade
FROM student
WHERE grade = (select max(grade) from student);

/*
40번 학과에서 학점이 가장 낮은 학생보다 학점이 더 높은 학생들의 이름과 학점, 그리고 학과를 출력
*/
select sname, grade, deptno
from student
where grade >any (select grade from student where deptno = 40)
order by grade desc;

/*
40번 학과에서 학점이 가장 높은 학생보다 학점이 더 높은 학생들의 이름과 학점, 그리고 학과를 출력
*/
select sname, grade, deptno
from student
where grade >all (select grade from student where deptno = 40)
order by grade desc;
