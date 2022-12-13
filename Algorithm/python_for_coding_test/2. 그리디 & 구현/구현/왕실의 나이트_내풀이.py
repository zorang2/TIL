# 답 보고 다시 작성
input_data = input()
row = int(input_data[1])
column = ord(input_data[0]) - ord('a') + 1

steps = [(1, 2), (2, 1), (2, -1),(1, -2), (-1, -2), (-2, -1), (-1, 2), (-2, 1)]
count = 0

for step in steps:
    x = row + step[0] # row 행
    y = column + step[1] # column 열
    count += 1
    if x < 1 or y < 1 or x > 8 or y > 8:
        count -= 1
print(count)



'''내 풀이
position = input()
x = [1, 2, 3, 4, 5, 6, 7, 8, 9] # 행
y = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'] # 열
'''