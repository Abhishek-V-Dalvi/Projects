from functools import reduce
CheckEven = lambda No : No % 2 == 0

Doubles = lambda No : No*2

Sum = lambda A,B : A+B

def main():
    print("Enter number of elements you want to enter : ")
    iSize = int(input())

    Data_Input = []
    print("Please enter the data : ")
    for iCnt in range(0,iSize,1):
        Value = int(input())
        Data_Input.append(Value)
    print("Data after input is : ",Data_Input)

    Data_Filter = list(filter(CheckEven, Data_Input))
    print("Data after filter : ",Data_Filter)

    Data_map = list(map(Doubles, Data_Filter))
    print("Data after map : ", Data_map)

    Data_Reduce = reduce(Sum,Data_map)
    print("Data after reduce is : ",Data_Reduce)

if __name__ == "__main__":
    main()