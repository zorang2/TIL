a = {
    '조랭이떡' : 'zorang',
    '홍길동' : 'hong'
}
print(a)

#사전 키
dict_key_list = a.keys()
print(dict_key_list)

#리스트로 변환해서 자주 사용함.
key_list = list(a.keys())
print(key_list)

#값 데이터만 담은 리스트
dict_value_list = a.values()
print(dict_value_list)

#각 key에 따른 value 하나씩 출력
for key in dict_key_list:
    print(a[key])

''' output
{'조랭이떡': 'zorang', '홍길동': 'hong'}
dict_keys(['조랭이떡', '홍길동'])
['조랭이떡', '홍길동']
dict_values(['zorang', 'hong'])
zorang
hong
'''