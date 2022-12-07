
def Display(No):
    if(No > 0):
        No -= 1
        Display(No)
        print(No)
        
Display(4)