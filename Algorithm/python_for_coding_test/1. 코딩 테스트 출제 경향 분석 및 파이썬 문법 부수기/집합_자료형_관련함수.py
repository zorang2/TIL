data = set([1, 2, 3])
print(data)

# 새로운 원소 1개 추가. add
data.add(4)
print(data)

# 새로운 원소 여러개 추가. updata
data.update([5,6])
print(data)

# 특정한 값을 갖는 원소 삭제. remove
data.remove(4)
print(data)

''' output
{1, 2, 3}
{1, 2, 3, 4}
{1, 2, 3, 4, 5, 6}
{1, 2, 3, 5, 6}
'''