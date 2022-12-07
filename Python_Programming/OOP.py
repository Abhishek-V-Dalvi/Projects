# Class = Characteistics + Behaviours
# Class = Data + Function
# Accept two numbers and perform addition and substraction of it
# Kay karaycha aahe --> Addition and substraction --> Behaviours
# Te karayala kay lagnar aahe --> 2 numbers --> Characteristics

class Arithmetic:
    def __init__(self,A,B):
        self.No1 = A
        self.No2 = B

    def Add(self):
        return self.No1 + self.No2

    def Sub(self):
        return  self.No1 - self.No2

def main():
    print("Enter first number : ")
    Value1 = int(input())

    print("Enter second number : ")
    Value2 = int(input())

    obj = Arithmetic(Value1,Value2)

    Ans = obj.Add()
    print("Addition is : ",Ans)

    Ans = obj.Sub()
    print("Substraction is : ", Ans)

if __name__ == "__main__":
    main()