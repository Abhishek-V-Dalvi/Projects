from sys import *

def main():
    print("Application name is : ",argv[0])
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