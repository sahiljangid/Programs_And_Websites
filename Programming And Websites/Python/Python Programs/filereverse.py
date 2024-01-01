import os
import sys


fname = input("Enter file Name: ")

if os.path.isfile(fname):
    print("File Exists: ", fname)
    f = open(fname, "r")
else:
    print("File doesn't exists: ", fname)
    sys.exit(0)

lines = f.readlines()
for line in lines:
    print(line[ : : -1])