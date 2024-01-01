import os
import sys


fname = input("Enter file Name: ")

if os.path.isfile(fname):
    print("File Exists: ", fname)
    f = open(fname, "r")
else:
    print("File doesn't exists: ", fname)
    sys.exit(0)


c = fname.split(".")
if c[1] == "txt":
    print("\n\nIt is a text file")
if c[1] == "c":
    print("\n\nIt is a c file")
if c[1] == "py":
    print("\n\nIt is a python file")
