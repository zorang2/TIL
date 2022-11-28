from collections import Counter

counter = Counter(['red', 'blue', 'red', 'green', 'blue', 'blue'])

print(counter['blue']) # blue가 등장한 횟수 출력
print(counter['green']) # green이 등장한 횟수 출력
print(dict(counter)) # 사전 자료형 반환

'''output
3
1
{'red': 2, 'blue': 3, 'green': 1}
'''