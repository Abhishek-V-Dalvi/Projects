
def Display(No):
    if(No > 0):
        print(No)
        No -= 1
        Display(No)

Display(4)