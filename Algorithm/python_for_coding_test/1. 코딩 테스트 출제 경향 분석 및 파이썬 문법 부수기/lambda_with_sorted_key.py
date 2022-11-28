array = [('홍길동', 50), ('이순신', 32), ('조랭이떡', 74)] #튜플 형태로 있는 리스트

def my_key(x):
    return x[1] #튜플(())의 2번째 원소를 기준으로 정렬 수행

print(sorted(array, key = my_key)) #정렬기준 my_key 함수
print(sorted(array, key = lambda x: x[1]))

'''output
[('이순신', 32), ('홍길동', 50), ('조랭이떡', 74)]
[('이순신', 32), ('홍길동', 50), ('조랭이떡', 74)]
'''