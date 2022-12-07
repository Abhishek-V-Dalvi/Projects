
def Add(A,B):
    return A+B

def Sub(A,B):
    return A-B

def Calculator(Name_Of_Operation,Value1,Value2):
    return Name_Of_Operation(Value1,Value2)

Ret = Calculator(Add,10,11)     #we can also call as per keyword argument - Calculator(Name_Of_Operation = Add, Value1 = 10, Value2 = 11)
print("Addition is : ",Ret)

Ret = Calculator(Sub,10,11)     #we can also call as per keyword argument - Calculator(Name_Of_Operation = Sub, Value1 = 10, Value2 = 11)
print("Substraction is : ",Ret)