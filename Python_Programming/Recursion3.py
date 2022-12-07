# define function which display 4 times hello on screen using recursion

def Display(No):
    if(No > 0):
        print("Hello")
        No -= 1
        Display(No)

Display(4)