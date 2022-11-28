from itertools import product #중복 순열

data = ['A', 'B', 'C'] # 데이터 준비.

result = list(product(data, repeat=2)) # 2개를 뽑는 모든 순열 구하기(중복허용)
print(result)

'''output
[('A', 'A'), ('A', 'B'), ('A', 'C'), ('B', 'A'), ('B', 'B'), ('B', 'C'), ('C', 'A'), ('C', 'B'), ('C', 'C')]
'''