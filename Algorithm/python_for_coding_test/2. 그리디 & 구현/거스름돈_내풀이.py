n = int(input())
coin = [500, 100, 50, 10]
count = 0
count_coin = 0
for i in coin:
    count_coin = n // i
    count += count_coin
    n = n - i * count_coin
    print(n, i, count)

print(count)



'''
n = int(input())
coin_count = 0

while True:
    #500
    result = n // 500
    exchange = n - (result * 500)
    coin_count += result

    #100
    result = exchange // 100
    exchange = exchange - (result * 100)
    coin_count += result
    
    #50
    result = exchange // 50
    exchange = exchange - (result * 50)
    coin_count += result
  
    #10
    result = exchange // 10
    exchange = exchange - (result * 10)
    coin_count += result
    

    if exchange == 0:
        break


    if exchange < 10:
        print("10원 단위로 다시 입력하세요.")
        break

print(coin_count)'''