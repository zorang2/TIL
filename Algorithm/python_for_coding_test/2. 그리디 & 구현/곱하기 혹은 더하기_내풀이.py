x = list(map(int, input()))

result = 0

for i in x:
    print(i)
    if 0 <= i <= 1:
        result += i
        print("0~1", result)
    elif result == 0:
        result += i
    else:
        result *= i
        print("2~9", result)
print(result)