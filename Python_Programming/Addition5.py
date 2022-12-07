print("Application to demonstrate industrial programming")

def main():
    print("Enter first number : ")
    no1 = input()
    print(type(no1))    #Every input is accepted as a string in Python

    print("Enter second number : ")
    no2 = input()
    print(type(no2))
    Ans = int(no1) + int(no2)

    print("Addition is : ",Ans)

if __name__ == '__main__':
    main()