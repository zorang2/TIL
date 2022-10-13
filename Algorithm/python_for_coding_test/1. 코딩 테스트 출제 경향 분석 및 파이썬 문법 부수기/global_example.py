a = 0

def func():
    global a
    a += 1

for i in range(10):
    func()

print(a)

'''output
10
'''