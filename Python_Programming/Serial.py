
def Square(No):
    return (No*No)

def main():
    Data = [1,2,3,4,5]
    Result = []

    for value in Data:
        Result.append(Square(value))
    print("Result after square operation is ",Result)

if __name__ == "__main__":
    main()