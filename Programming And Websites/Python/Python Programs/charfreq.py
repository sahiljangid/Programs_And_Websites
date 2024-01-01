import os
import sys


fname = input("Enter file Name: ")

if os.path.isfile(fname):
    print("File Exists: ", fname)
    f = open(fname, "r")
else:
    print("File doesn't exists: ", fname)
    sys.exit(0)



freq = { }

for lines in f:
    for ch in lines:
        if ch in freq:
            freq[ch] += 1
        else:
            freq[ch] = 1

print(freq)


