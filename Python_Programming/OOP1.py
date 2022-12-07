
class Arithmetic:

    def __init__(self,A,B):
        print("Inside init method")
        self.No1 = A
        self.No2 = B

    def Addition(self):
        Ans = self.No1 + self.No2
        return Ans

    def Substraction(self):
        Ans = self.No1 - self.No2
        return Ans

def main():
    print("Inside main method")

    obj = Arithmetic(11,10)
    Output = obj.Addition()
    print("Addition is : ",Output)

    Output = obj.Substraction()
    print("Substraction is : ", Output)

if __name__ == "__main__":
    print("Inside starter")
    main()