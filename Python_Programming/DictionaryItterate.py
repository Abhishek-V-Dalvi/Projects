Batches = {"PPA" : 18000, "LB":16700, "Python":16500, "Angular":15000}

print("Data of dictionary : ",Batches)

print("Data traversal using for loop")
for x in Batches:
    print(x)

print("Data traversal using for loop")
for x in Batches:
    print(x,Batches[x])

print("Data traversal using for loop")
for x in Batches:
    print(x,Batches.get(x))

keyBatches = Batches.keys()
print(keyBatches)
print(type(keyBatches))

valueBatches = Batches.values()
print(valueBatches)
print(type(valueBatches))

for i in range(0,len(Batches)) :
    print("Batch name is : ",keyBatches[i], end = " ")
    print("Fees are : ",valueBatches[i])
# =    _