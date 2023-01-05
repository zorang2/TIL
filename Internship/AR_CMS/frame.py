import pandas as pd

Location = '/media/sldev1/T7/AR CMS Dataset/CV22 결과/'
File = 'AR CMS Frame 추출_230105.xlsx'

# 추출 행, 열 선언
Row = 1
Column = list(range(50))



# 추출 및 변환 코드
data_pd = pd.read_excel('{}/{}'.format(Location, File), header=0, index_col=None, names=None, engine='openpyxl')
data_np = pd.DataFrame.to_numpy(data_pd)
# print(data_np["221118_LH_1_1"])





# 출력
# print(data_pd)
# print(data_np[0][0])
# print(data_np[0:28][:])
# x = data_np[0:28][:]
# print(x.size())

max = 1288


for i in range(max):
    print(data_np[i][0])




'''
총 28행
1열 = 파일명
2열 = frame
'''