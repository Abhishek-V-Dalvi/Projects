
CheckEven = lambda No : No % 2 == 0

Doubles = lambda No : No*2

Sum = lambda A,B : A+B

def filterX(Helper_Function,Data):
    Result = []
    for no in Data:
        if(Helper_Function(no) == True):
            Result.append(no)
    return Result

def mapX(Helper_Function,Data):
    Result = []
    for no in Data:
        Value = Helper_Function(no)
        Result.append(Value)
    return Result

def reduceX(Helper_Function, Data):
    Ans = 0
    for no in Data :
        Ans = Helper_Function(Ans,no)
    return Ans

def main():
    print("Enter number of elements you want to enter : ")
    iSize = int(input())

    Data_Input = []
    print("Please enter the data : ")
    for iCnt in range(0,iSize,1):
        Value = int(input())
        Data_Input.append(Value)
    print("Data after input is : ",Data_Input)

    Data_Filter = filterX(CheckEven, Data_Input)
    print("Data after filter : ",Data_Filter)

    Data_map = mapX(Doubles, Data_Filter)
    print("Data after map : ", Data_map)

    Data_Reduce = reduceX(Sum,Data_map)
    print("Data after reduce is : ",Data_Reduce)

if __name__ == "__main__":
    main()