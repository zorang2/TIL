n = int(input())
path = input().split()

# L R U D
dy = [-1, 1, 0, 0]  # 열 이동
dx = [0, 0, -1, 1]  # 행 이동
move_types = ['L', 'R', 'U', 'D']


x, y = 1, 1
map = [n-1, n-1]

for i in path: # RRRDU
    for j in range(len(move_types)):
        if i == move_types[j]:
            nx = x + dx[j]
            ny = y + dy[j]
    #
    if nx < 1 or ny < 1 or nx > n or ny > n:
        continue
    x, y = nx, ny

print(x, y)
