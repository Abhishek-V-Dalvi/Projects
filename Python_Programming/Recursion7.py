# 4
# 4 + 3 + 2 + 1 = 10

def Add(No):
    if(No <= 0):
        return 0
    else:
        return (No + Add(No-1))

Ret = Add(4)
print("Result is : ",Ret)

'''
Itterative approach

def Add(No):
    Ans = 0
    while(No >= 0):
        Ans = Ans + No
        No -= 1
    return Ans

Ret = Add(4)
print("Result is : ",Ret)
'''