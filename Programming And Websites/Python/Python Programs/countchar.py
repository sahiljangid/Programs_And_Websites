str=input("Enter a String: ")
dict = { }
for i in str: 
    dict[i] = str.count(i)
print (dict)