a = (1, 2, 3, 4, 5, 6, 7, 8, 9)

#네 번째 원소만 출력
print(a[3])

#두 번째 원소부터 네 번째 원소까지 출력
print(a[1:4])

#특정 인덱스 값 바꾸는 예제(오류 출력됨)
print(a)
a[2] = 7

'''output
4
(2, 3, 4)
(1, 2, 3, 4, 5, 6, 7, 8, 9)
Traceback (most recent call last):
  File "main.py", line 11, in <module>
    a[2] = 7
TypeError: 'tuple' object does not support item assignment
(=튜플은 변경 불가 객체라서 원소 할당 연산은 지원하지 않는다.)
'''