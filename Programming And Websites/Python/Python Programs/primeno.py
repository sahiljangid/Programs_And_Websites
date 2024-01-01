
def isPrime(x):

    returnVal = True

    for i in range(2, int(x)):

        if (int(x) % i) == 0:
            returnVal = False
            break
    return returnVal


s = 2

for j in range(3, 2000000):
    if isPrime(j):
        print("adding := ", j)
        s = s + j
print("Result := ", s)
