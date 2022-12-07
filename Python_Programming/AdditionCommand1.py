from sys import *

def main():
    print("Welcome to : ",argv[0])
    if(argv[1] == "--U"):
        print("Use the application as : ")
        print("python Name_Of_Application First_Number Second_Number")
    if(len(argv) != 3):
        print("Invalid number of argument")
        exit()
        
    ret = Addition(int(argv[1]), int(argv[2]))
    print("Addition is : ",ret)
    
def Addition(No1,No2):
    Ans = No1+No2
    return Ans;

if __name__ == '__main__':
    main()