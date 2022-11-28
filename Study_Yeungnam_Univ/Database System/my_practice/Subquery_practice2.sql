/* 여러개의 필드 비교

학과별로 학점이 가장 높은 학생의 이름과 학점, 그리고 학과번호를 출력하라.

in 앞에 필드가 하나 이상일 경우, Subquery의 select 절에서도 동일한 수의 필드가 필요.

*/
select sname, grade, deptno
from student
where (grade, deptno) in
  (select max(grade), deptno from student group by deptno);


/*이건 올바른 질의문이 아니다.*/
select sname, grade, deptno
from student
where grade in
  (select max(grade) from student group by deptno);
