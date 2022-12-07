# define function which display 4 times hello on screen using recursion

def Display(No):
    Cnt = 0
    
    if(Cnt < No):
        print("Hello")
        Cnt += 1
        Display(No)

Display(4)