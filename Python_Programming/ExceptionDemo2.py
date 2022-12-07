
def main():
    try:
        print("Enter first number : ")
        No1 = int(input())

        print("Enter second number : ")
        No2 = int(input())


        Ans = No1/No2
        print("Division is : ",Ans)

    except ZeroDivisionError:
        print("Inside ZeroDivisionError")

    except ValueError:                      #Will execute if input is other than integer
        print("Inside ValueError")

    except Exception:
        print("Inside last except block")

    finally:                                #Finally block will execute irrespective of exception
        print("Inside finally block")       #Finally block execute in each and every case

if __name__ == "__main__":
    main()