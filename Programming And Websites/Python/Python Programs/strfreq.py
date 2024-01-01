
a = input("Enter an string")
d = { }

for x in a:
    if x in d.keys():
        d[x] += 1
    else:
        d[x] = 1

print(d)