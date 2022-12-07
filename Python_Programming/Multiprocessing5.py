import time
import  multiprocessing

def DisplayEven(No):
    for i in range(1,No+1,1):
        if(i % 2 == 0):
            print("Even Number : ",i)

def DisplayOdd(No):
    for i in range(1,No+1,1):
        if(i % 2 != 0):
            print("Odd  Number : ",i)

def main():
    print("Demonstration of parallel programming using multiple processes")
    Number = 2000

    P1 = multiprocessing.Process(target = DisplayEven,args= (Number,))
    P2 = multiprocessing.Process(target = DisplayOdd,args= (Number,))

    P1.start()
    P2.start()

    P1.join()
    P2.join()

    print("End of main")

if __name__ == "__main__":
    start_time = time.process_time()        # by this method we can get actual time given by OS to process
    main()
    end_time = time.process_time()
    print("Execution time is : ",end_time - start_time)