from itertools import combinations

data = ['A', 'B', 'C'] # 데이터 준비.

result = list(combinations(data, 2)) # 2개를 뽑는 모든 조합 구하기
print(result)

'''output
[('A', 'B'), ('A', 'C'), ('B', 'C')]
'''