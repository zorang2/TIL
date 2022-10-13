# 올바른 방법
n = 4
m = 3

array = [ [0] * m for _ in range(n) ]
print(array)
''' output
[[0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0]]
'''


# 잘못된 방법
# N x M 크기의 2차원 리스트 초기화
n = 4 #행
m = 3 #열
array = [ [0] * m ] * n

print([0] * m)
print(array)

''' output
[0, 0, 0]
[[0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0]]
'''


array[1][1] = 5
print(array)

''' output
[[0, 5, 0], [0, 5, 0], [0, 5, 0], [0, 5, 0]]
'''