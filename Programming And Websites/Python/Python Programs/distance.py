import math

# Formula := d=√((x2 – x1)² + (y2 – y1)²)

x1 = int(input("Enter x1: "))
x2 = int(input("Enter x2: "))
y1 = int(input("Enter y1: "))
y2 = int(input("Enter y2: "))

d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)

dist = math.pow(d, 0.5)

print(dist)
