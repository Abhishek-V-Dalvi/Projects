#List
# Data      : Heterogeneous
# Ordered   : Yes
# Indexed   : Yes
# Mutable   : Yes
# Duplicate : Yes

data = [11,21,51,101]

print("Output using for")
for no in data :
    print(no, end = " ")
print("\n-------------------------------------")

print("Output using for with index")
for i in range(0,len(data)) :
    print(data[i], end = " ")
print("\n-------------------------------------")

print("Output using while with index")
i = 0
while(i<len(data)) :
    print(data[i], end = " ")
    i+=1    #i = i + 1
print("\n-------------------------------------")

# =    _