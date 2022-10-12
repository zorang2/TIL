array = [1, 2, 3, 4, 5]

def func():
    array = [3, 4, 5]
    array.append(6)
    print(array)

func()
print(array)

'''output
[3, 4, 5, 6]
[1, 2, 3, 4, 5]
'''