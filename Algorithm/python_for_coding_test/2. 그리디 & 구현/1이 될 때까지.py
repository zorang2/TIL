#n, k 공백 기준으로 구분하여 입력받기
n, k = map(int, input().split())

result = 0

while True:
  # N이 K로 나누어 떨어지는 수가 될 때까지만 1씩 빼기  
    target = (n // k) * k # n이 k로 나누어 떨어지는 값 = target
    result += (n - target) # n - target = 나머지, 즉 나머지를 result에 넣는다.
                           # 즉, 1을 빼는 연산을 몇 번 수행할 지에 대한 내용.
    n = target # 1씩 뺀 값인 target으로 n을 최신화

    # N이 K보다 작을 때 (더 이상 나눌 수 없을 때) 반복문 탈출
    if n < k:
      break
    
    # k로 나누기
    result += 1 # k로 나눠주는 연산을 1번 수행한 것이므로 +1 시킨다.
    n //= k # n을 k로 나눈다.

# 마지막으로 남은 수에 대하여 1씩 빼기
result += (n-1)
print(result)


'''output
26 5
3
'''