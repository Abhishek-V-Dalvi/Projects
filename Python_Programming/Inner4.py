
def Outer():
    print("Inside outer")
    print(id(Outer))
    def Inner():
        print("Inside inner")
        print(id(Inner))

    return Inner

ret = Outer()
print(type(ret))
print(id(ret))
ret()