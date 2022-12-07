def main():
    print("Enter number : ")
    No = int(input())

    print("Factors are : ")
    i = 1
    while (i <= int(No/2)):
        if No % i == 0 :
            print(i)
        i = i + 1

if __name__ == '__main__':
    main()

