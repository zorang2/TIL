result = 0

for i in range(1, 10):
    if i % 2 == 0:
        continue
    result += i
print(result)