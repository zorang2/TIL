import modtest

class FourCal:
    def setdata(self, first, second):
        self.first = first
        self.second = second

a = FourCal()
a.setdata(4, 2)
print(a.first, a.second)

'''

* env py3.6 version 정리
    torch : 1.10.0
    파이참 터미널 cuda : 9.1.85
    로컬 터미널 cuda : 10.2.89

* env py3.7 version 정리
    torch : 1.7.0
    파이참 터미널 cuda : 9.1.85
    로컬 터미널 cuda : 10.2.89
    
목표 : 15333
torch vision mnist dataset 불러오기
classification cifar-100
'''

