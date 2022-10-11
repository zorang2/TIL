#0부터 9까지의 수를 포함하는 리스트.
array = [ i for i in range(10)]
print(array)
# output : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

#0부터 19까지의 수 중에서 짝수만 포함하는 리스트
array = [ i for i in range(20) if i % 2 == 0]
print(array)
# output : [0, 2, 4, 6, 8, 10, 12, 14, 16, 18]

#1부터 9까지의 수들의 제곱 값을 포함하는 리스트
array = [ i * i for i in range(1, 10)]
print(array)
# output : [1, 4, 9, 16, 25, 36, 49, 64, 81]