from itertools import combinations_with_replacement

data = ['A', 'B', 'C'] # 데이터 준비.

result = list(combinations_with_replacement(data, 2)) # 2개를 뽑는 모든 순열 구하기(중복허용)
print(result)

'''output
[('A', 'A'), ('A', 'B'), ('A', 'C'), ('B', 'B'), ('B', 'C'), ('C', 'C')]
'''