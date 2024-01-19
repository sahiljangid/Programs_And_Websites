#
# class tree:
#     ## Creation of node and initialize the data part of the node with given data
#     def __init__(self, data):
#         self.data = data
#         self.left = None
#         self.right = None
#
#     ###################### Insertion ######################
#     def insert(self, data): ## Insert data according to the BST
#
#         if self.data == data: ### Same data can't be inserted
#             return
#
#         if data < self.data: ## true if data(which we want ot insert) is smaller than the current node data
#             if self.left: ## true if left node is present
#                 self.left.insert(data) ## pointer move on the left node
#             else:
#                 self.left = tree(data) ## node is added in left side of the tree
#         else: ## no condition available but the meaning is that the data(which we want to insert) is greater than the current node data
#             if self.right: ## true if right node is present
#                 self.right.insert(data) ## pointer move on the right node
#             else:
#                 self.right = tree(data) ## node is added in the right side of the tree
#
#     ###################### Traversal ######################
#
#     ## Pre-order traversal
#     def preorder(self):
#         print(self.data, end=' ') ## print the data
#         if self.left: ## true if left node is present in the tree
#             self.left.preorder() ## move left side of the tree
#         if self.right: ## true if right ndoe is present in the tree
#             self.right.preorder() ## move right side of the tree
#
#     ## In-order traversal
#     def inorder(self):
#         if self.left: ## true if the left node is present in the tree
#             self.left.inorder()  ## move left side of the tree
#
#         print(self.data, end=' ') ## print the data
#
#         if self.right: ## true if the right node is present in the tree
#             self.right.inorder() ## move right side of the tree
#
#
#     ## Post-order traversal
#     def postorder(self):
#         if self.left: ## true if the left node is present in the tree
#             self.left.postorder() ## move left side of the tree
#         if self.right: ## true if the right node is present in the tree
#             self.right.postorder() ## move right side of the tree
#         print(self.data, end=' ') ## print the data
#
#
#     ###################### Searching ######################
#     def search(self, n):
#         if n == self.data: ## true if n is equal to the data of the present node
#             print("Data is present in the tree")
#             return
#         if n < self.data: ## true if the searching data is smaller than the current node data
#             if self.left: ## move on left side of the tree
#                 if n == self.data:
#                     print("Data is present in the tree")
#                     return
#                 self.left.search(n)
#             else:
#                 print("Data is not present in the tree")
#
#
#         else: ## true when searching data is greater than the current node data
#             if self.right: ## move on right side of the tree
#                 if n == self.data:
#                     print("Data is present in the tree")
#                     return
#                 self.right.search(n)
#             else:
#                 print("Data is not present in the tree")
#
#     ###################### Deletion ######################
#     def delete(self, d):
#         if d == self.data:
#             if self.left is None and self.right is None:
#                 return None
#             elif self.left is None:
#                 return self.right
#             elif self.right is None:
#                 return self.left
#             else:
#                 ptr = self.right
#                 while ptr.left:
#                     ptr = ptr.left
#                 self.data = ptr.data
#                 self.data = self.right.delete(ptr.data)
#         elif d < self.data:
#             if self.left:
#                 self.left = self.left.delete(d)
#         else:
#             if self.right:
#                 self.right = self.right.delete(d)
#         return self
#
#
#
#
#
# root = tree(10) # instance of the tree class
# print("root is : ",root.data)
# lst = [20,4,30,4,1,5,6]
# print("Data is: ",end=' ')
# for i in lst:
#     print(i, end=' ')
# print()
#
# for i in lst:
#     root.insert(i)
# ## Print element according to the preorder traversal
# print("Pre-order Traversal: ", end=' ')
# root.preorder()
# print()
# ## Print element according to the inorder traversal
# print("In-order Traversal: ", end=' ')
# root.inorder()
# print()
# ## Print element according to the postorder traversal
# print("Post-order Traversal: ", end=' ')
# root.postorder()
# print()
# ## Search element in the tree
# print("Enter the data which you want to search in the tree: ", end=' ')
# n = int(input())
# root.search(n)
#
# print("Pre-order Traversal: ", end=' ')
# root.preorder()
# print()
# print("Enter the data which you want to delete in the tree: ", end=' ')
# d = int(input())
# root.delete(d)
# print("Pre-order Traversal: ", end=' ')
# root.preorder()
# print()
#

##################################### Level Order Traversal ######################################################
# Recursive Python program for level
# order traversal of Binary Tree


# A node structure
class Node:

	# A utility function to create a new node
	def __init__(self, key):
		self.data = key
		self.left = None
		self.right = None


# Function to print level order traversal of tree
def printLevelOrder(root):
	h = height(root)
	for i in range(1, h+1):
		printCurrentLevel(root, i)


# Print nodes at a current level
def printCurrentLevel(root, level):
	if root is None:
		return
	if level == 1:
		print(root.data, end=" ")
	elif level > 1:
		printCurrentLevel(root.left, level-1)
		printCurrentLevel(root.right, level-1)


# Compute the height of a tree--the number of nodes
# along the longest path from the root node down to
# the farthest leaf node
def height(node):
	if node is None:
		return 0
	else:
		# Compute the height of each subtree
		lheight = height(node.left)
		rheight = height(node.right)

		# Use the larger one
		if lheight > rheight:
			return lheight+1
		else:
			return rheight+1


# Driver program to test above function
if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)

	print("Level order traversal of binary tree is -")
	printLevelOrder(root)

# This code is contributed by Nikhil Kumar Singh(nickzuck_007)
