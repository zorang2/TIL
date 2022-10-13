i = 1
result = 0

# i가 9보다 작거나 같을 때 아래 코드 반복
while i <= 9:
    if i % 2 == 1: #1부터 9까지 홀수 합 구하기
        result += i
    i += 1

print(result)

''' output
25
'''