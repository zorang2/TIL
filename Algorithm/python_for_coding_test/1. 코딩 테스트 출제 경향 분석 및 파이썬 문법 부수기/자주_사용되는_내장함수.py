#자주 사용되는 내장함수

# sum() = (다수의 데이터를 포함하는) 리스트나 튜플들이 들어왔을 때 그 원소의 합을 반환
result = sum([1, 2, 3, 4, 5])
print(result)

# min(), max()
min_result = min(7, 3, 5, 2)
max_result = max(7, 3, 5, 2)
print(min_result, max_result)

# eval() = 사람의 입장에서 수식으로 표현된 식이 있을 때 그 것을 계산해서 숫자로 반환.
result = eval("(3+5)*7")
print(result)

# sorted()
result = sorted([9, 1, 8, 5, 4]) # 오름차순
reverse_result = sorted([9, 1, 8, 5, 4], reverse = True) # 내림차순
print(result)
print(reverse_result)

# sorted() with key
array = [('홍길동', 35), ('이순신', 75), ('조랭이떡', 50)]
result = sorted(array, key = lambda x: x[1], reverse = True)
#key는 정렬 기준인데, 일반적으로 lambda를 활용해서 넣는 경우가 많다.
print(result)


'''output
15
2 7
56
[1, 4, 5, 8, 9]
[9, 8, 5, 4, 1]
[('이순신', 75), ('조랭이떡', 50), ('홍길동', 35)]
'''