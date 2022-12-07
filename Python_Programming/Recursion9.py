# 4
# 4 * 3 * 2 * 1 = 24

def Factorial(No):
    if(No <= 0):
        return 1
    else:
        return (No * Factorial(No-1))

Ret = Factorial(4)
print("Result is : ",Ret)

'''
#Itterative approach

def Factorial(No):
    Ans = 1
    while(No > 0):
        Ans = Ans * No
        No -= 1
    return Ans

Ret = Factorial(4)
print("Result is : ",Ret)
'''