import math
from functools import reduce
def SolveErrorA(OrigData):
    summary=reduce(lambda x,y:x+y,OrigData)
    average=summary/len(OrigData)
    Weight_A_List=map(lambda x:(x-average)*(x-average),OrigData)
    Weight_A=reduce(lambda x,y:x+y,Weight_A_List)
    Weight_A=math.sqrt(Weight_A/(len(OrigData)*(len(OrigData)-1)))
    return [Weight_A,average]
def SolveErrorB(OrigData):
    return OrigData/math.sqrt(3)
def SolveErrorC(A,B):
    return math.sqrt(A*A+B*B)
A_str_in = input('求不确定度的A类分量，用空格分隔多个数据:')
ErrorB_OrigData = float(input('求不确定度的B类分量，请输入极限误差:'))
ErrorA_OrigData = [float(n) for n in A_str_in.split()]
ErrorA=SolveErrorA(ErrorA_OrigData)
ErrorB=SolveErrorB(ErrorB_OrigData)
ErrorC=SolveErrorC(ErrorA[0],ErrorB)
print('该组数据的不确定度的A类分量为：%s，平均值为：%s'%(ErrorA[0],ErrorA[1]))
print('该组数据的不确定度的B类分量为：%s'%ErrorB)
print('该组数据的合成不确定度为：%s'%ErrorC)
End=input('按回车键结束。')
