#데이터의 개수 입력
n = int(input())

#그냥 input만 썻을 경우
data = input()
print(data)

#각 데이터를 공백을 기준으로 구분하여 입력시 리스트 안에 문자열로 return.
data = input().split()
print(data)

#문자열을 없애기 위해 map함수를 이용해 각각의 문자열을 정수형으로 바꿔주고 list로 감싼다.
data = list(map(int, input().split()))
print(data)

#데이터가 몇개 들어온다고 명시 되어 있는 경우
a, b, c = map(int, input().split())
print(a, b, c)

'''
map으로 저렇게 묵는걸 packing이라고 한다
묵어 놓은 것을 푸는 걸 unpacking이라고 한다.
unpacking할 때 데이터 개수가 서로 동일해야 Error 안난다.
'''



''' output
5 //입력
1 2 3 //입력
1 2 3 
4 5 6 //입력
['4', '5', '6']
7 8 9 //입력
[7, 8, 9]
10 11 12 //입력
10 11 12
'''