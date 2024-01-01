l1 = [10,20,30]
print(l1)
print(type(l1))

l2 = [10,20.34,'sahil',10+5j]
print(l2)
type(l2)

# creation type of list

l3 = []
print(l3)
type(l3)

l4 = [10,20,30,50]
print(l4)
type(l4)

# l5 = eval(input("Enter a list"))
# print(l5)
# type(l5)

l6 = list(range(1,21))
print(l6)
type(l6)

s = "Learning python is very very easy"
l7 = s.split()
print(l7)
type(l7)

# Accessing list element

l8 = [10,20,30,40,50]
print(l8[0])
print(l8[0:3:1])

# important functions of list
l9 = [22,5,37,3,9,21,75,33]
print(len(l9))
l9.sort()
print(l9)

l10 = [1,1,34,53,235,43,32,34,2,1,1,1]
print(l10.count(1))
print(l10.index(34))

l11 = []
l11.append(10)
l11.append(20)
l11.append(30)
l11.append(40)
l11.insert(1,50)
l11.remove(50)
l11.pop() # return value
l11.clear() # for clear the entire list
print(l11)
print(type(l11))

a = [12,32,3,5,3,5,76]
b = [23,54,5,575,7,64,53]
c = (a*2)+b
print(c)


# Tuple possible operation

t1 = ()
print(t1)
print(type(t1))

t2 = (12,32,43,545.34,'sahil')
print(t2)

t3 = tuple(list(range(1,21)))
print(t3)

s = "Learning python is very very easy"
t4 = tuple(s.split())
print(t4)

t5 = (10,20,30,40,50)
print(t5[0])
print(t5[0:3:1])

t6 = (22,5,37,3,9,21,75,33)
print(len(t6))


t7 = (1,1,34,53,235,43,32,34,2,1,1,1)
print(t7.count(1))
print(t7.index(34))
print(t7)
print('hey sahil')


t8 = (12,32,3,5,3,5,76)
t9 = (23,54,5,575,7,64,53)
c = tuple((a*2)+b)
print(c)











