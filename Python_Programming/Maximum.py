def maximum(No1, No2):
    if No1 > No2:
        return No1
    else:
        return No2

def main():
    print("Enter first number : ")
    value1 = input()

    print("Enter second number : ")
    value2 = input()

    ans = maximum(int(value1),int(value2))
    print("Maximum number is : ",ans)

if __name__ == "__main__":
    main()