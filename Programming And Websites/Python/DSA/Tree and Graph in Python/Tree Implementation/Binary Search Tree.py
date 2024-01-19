
class tree:
    ## Creation of node and initialize the data part of the node with given data
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    ###################### Insertion ######################
    def insert(self, data): ## Insert data according to the BST

        if self.data == data: ### Same data can't be inserted
            return

        if data < self.data: ## true if data(which we want ot insert) is smaller than the current node data
            if self.left: ## true if left node is present
                self.left.insert(data) ## pointer move on the left node
            else:
                self.left = tree(data) ## node is added in left side of the tree
        else: ## no condition available but the meaning is that the data(which we want to insert) is greater than the current node data
            if self.right: ## true if right node is present
                self.right.insert(data) ## pointer move on the right node
            else:
                self.right = tree(data) ## node is added in the right side of the tree

    ###################### Traversal ######################

    ## Pre-order traversal
    def preorder(self):
        print(self.data, end=' ') ## print the data
        if self.left: ## true if left node is present in the tree
            self.left.preorder() ## move left side of the tree
        if self.right: ## true if right ndoe is present in the tree
            self.right.preorder() ## move right side of the tree

    ## In-order traversal
    def inorder(self):
        if self.left: ## true if the left node is present in the tree
            self.left.inorder()  ## move left side of the tree

        print(self.data, end=' ') ## print the data

        if self.right: ## true if the right node is present in the tree
            self.right.inorder() ## move right side of the tree


    ## Post-order traversal
    def postorder(self):
        if self.left: ## true if the left node is present in the tree
            self.left.postorder() ## move left side of the tree
        if self.right: ## true if the right node is present in the tree
            self.right.postorder() ## move right side of the tree
        print(self.data, end=' ') ## print the data

    ## Level-Order Traversal
    def levelorder(self):
        if not self: ## True if tree is empty
            return
        queue = []
        queue.append(self) ## Append root node into queue
        while queue: ## True till queue is not empty
            node = queue.pop(0) ## Pop first element into the queue
            print(node.data, end=" ") ## print the current element
            if node.left: ## True if left node is present
                queue.append(node.left) ## Append left node data into queue
            if node.right: ## True is right node is present
                queue.append(node.right) ## Append right node data into queue

    ## Height of the tree
    def height(self):
        if self is None:  # Base case: If the tree is empty
            return 0
        else:
            left_height = 0 if self.left is None else self.left.height()
            right_height = 0 if self.right is None else self.right.height()
            return max(left_height, right_height) + 1


    ###################### Searching ######################
    def search(self, n):
        if n == self.data: ## true if n is equal to the data of the present node
            print("Data is present in the tree")
            return
        if n < self.data: ## true if the searching data is smaller than the current node data
            if self.left: ## move on left side of the tree
                if n == self.data:
                    print("Data is present in the tree")
                    return
                self.left.search(n)
            else:
                print("Data is not present in the tree")


        else: ## true when searching data is greater than the current node data
            if self.right: ## move on right side of the tree
                if n == self.data:
                    print("Data is present in the tree")
                    return
                self.right.search(n)
            else:
                print("Data is not present in the tree")

    ###################### Deletion ######################
    def delete(self, d):
        if self.data is None:
            print("Tree is empty")
            return
        if self.data == d: ## Node to be deleted is found
            if self.left is None and self.right is None: ## Node to be deleted is a leaf node
                return None
            elif self.left is None: ## Node to be deleted has only right child
                return self.right
            elif self.right is None: ## Node to be deleted has only left child
                return self.left
            else: ## Node to be deleted has both left and right children
                ptr = self.right
                while ptr.left: ## Finding the minimum element from the right subtree
                    ptr = ptr.left
                self.data = ptr.data ## Replacing the data of the node to be deleted with the successor data
                self.right = self.right.delete(ptr.data) ## Deleting the successor
        elif d < self.data: ## Node to be deleted lies in the left subtree
            if self.left:
                self.left = self.left.delete(d)
            else:
                print("Given node is not present")
        else: ## Node to be deleted lies in the right subtree
            if self.right:
                self.right = self.right.delete(d)
            else:
                print("Given node is not present")
        return self

    ###################### Print Minimum Data ######################
    def mindata(self):
        ptr = self
        while ptr.left:
            ptr = ptr.left
        print("Minimum data is: ", ptr.data)

    ###################### Print Maximum Data ######################
    def maxdata(self):
        ptr = self
        while ptr.right:
            ptr = ptr.right
        print("Maximum data is: ", ptr.data)


##### Drive code


root = tree(10) # instance of the tree class
print("root is : ",root.data)
lst = [20,4,30,4,1,5,6]
print("Data is: ",end=' ')
for i in lst:
    print(i, end=' ')
print()

for i in lst:
    root.insert(i)
## Print elements according to the preorder traversal
print("Pre-order Traversal: ", end=' ')
root.preorder()
print()
## Print elements according to the inorder traversal
print("In-order Traversal: ", end=' ')
root.inorder()
print()
## Print elements according to the postorder traversal
print("Post-order Traversal: ", end=' ')
root.postorder()
print()
## Print elements according to the level order traversal
print("\nLevel-order Traversal: ", end=' ')
root.levelorder()
print()
## Search element in the tree
print("Enter the data which you want to search in the tree: ", end=' ')
n = int(input())
root.search(n)

print("Pre-order Traversal: ", end=' ')
root.preorder()
print()
## Delete an element into the tree
print("Enter the data which you want to delete in the tree: ", end=' ')
d = int(input())
root.delete(d)
print("Pre-order Traversal: ", end=' ')
root.preorder()
print()
root.mindata()
root.maxdata()
print("Height of the tree:", root.height())

