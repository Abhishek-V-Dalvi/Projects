print("Demonstration of set")

# Data      : Heterogeneous
# Ordered   : No
# Indexed   : No
# Mutable   : Yes
# Duplicate : No

data = {11,21,51,101,21,11}
data1 = {11,90.80,True,"Hello"} #Heterogeneous

print("First set data : ",data) #duplicates automatically removed in set
print("Length of data : ",len(data))
print("Data is heterogeneous : ",data1)
print("Data is not ordered : ",data1)
# print("Data at index 2 : ",data1[2]) not used in set
print("Data with unique elements : ",data)

print("Set is mutable")
#insert element in set
data.add(211)
print("Data after insertion : ",data)

# Remove element
data.remove(211)    #if the value is there in set then remove function will remove the value and if not there in list it will generate error as "Kay error"
print("Data after removal : ",data)

data.discard(201) #discard function remove the data if it is present but will not show any error if there is no data
print("Data after discard : ",data)

# =    _