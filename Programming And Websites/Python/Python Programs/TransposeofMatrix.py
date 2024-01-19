def transpose(arr):
    # Transpose process
    for i in range(row):
        for j in range(i + 1, col):
            d = arr[i][j]
            arr[i][j] = arr[j][i]
            arr[j][i] = d
            # arr[i][j], arr[j][i] = arr[j][i], arr[i][j]

row = int(input("Enter how many rows in the matrix: "))
col = int(input("Enter how many columns in the matrix: "))

# ar = [[0]*row]*col
# print(ar)
arr = [[0] * col for _ in range(row)]

print("Enter the elements of the matrix one by one: ")
for i in range(row):
    for j in range(col):
        d = int(input())
        arr[i][j] = d

print("Your matrix is: ")
for i in range(row):
    for j in range(col):
        print(arr[i][j], end=' ')
    print()

transpose(arr)

print("Transpose of the matrix is: ")
for i in range(row):
    for j in range(col):
        print(arr[i][j], end=' ')
    print()




