import os
import sys

lcount = wcount = ccount = 0


fname = input("Enter file Name: ")
if os.path.isfile(fname):
    print("File Exists: ", fname)
    f = open(fname, "r")
    for line in f:
        lcount = lcount + 1
        ccount = ccount + len(line)
        words = line.split()
        wcount = wcount + len(words)

else:
    print("File doesn't exists: ", fname)
    sys.exit(0)

print("The no. of lines: ",lcount)
print("The no. of characters: ",ccount)
print("The no. of words: ",wcount)
