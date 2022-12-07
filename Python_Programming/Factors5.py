#import Numbers # First way of writting
#from Numbers import DisplayFactors # Second way of writting
#from Numbers import * #third way of writting
import Numbers as NUM #fourth way of writting

def main():
    print("Enter number : ")
    No = int(input())
    #Numbers.DisplayFactors(No) # First way calling
    #DisplayFactors(No) #Function calling technique for second and third way
    NUM.DisplayFactors(No) #Function calling technique for fourth way of writting
    
if __name__ == '__main__':
    main()

