# Decorator demonstration

def Substraction(No1,No2): #ID - 200    #Consider like substraction function is not allowed to edit anything
    Ans = 0
    Ans = No1 - No2
    return Ans

def Decorated_Function(Function_Name):  # Decorated_Function ID - 400 & Function_Name = 200
    def Inner(A,B): # ID - 300
        if(A < B):
            A,B = B,A
        Output = Function_Name(A,B) # Output = 200(12,8)
        return Output
    return Inner     #return 300       #After line 8 call gets to line 13

def main():         # ID - 100
    Value1 = int(input("Enter first number : "))        #Value1 = 8
    Value2 = int(input("Enter second number : "))       #Value2 = 12

    New_Function = Decorated_Function(Substraction)     #New_Function = 400(200)
    Ret = New_Function(Value1,Value2)  #Ret = 300(8,12)
    print("Substraction is : ",Ret)

if __name__ == "__main__":
    main()  # call 100()