class BST:
    def __init__(self, val=None):
        self.parent = None
        self.left = None
        self.right = None
        self.val = val

    def insert(self, val):
        if not self.val:
            self.val = val
            return

        if not self.left:
            self.left = BST(val)
            self.left.parent = self
            return

        if self.left.val != 0:
            self.left.insert(val)
            return

        if not self.right:
            self.right = BST(val)
            self.right.parent = self
            return

        if self.right.val != 0:
            self.right.insert(val)
            return

        temp = self.parent
        while not temp.can_insert():
            temp = temp.parent

        if not temp.right:
            temp.right = BST(val)
            temp.right.parent = self
            return

        temp.right.insert(val)

    def can_insert(self):
        if self.val == 0:
            return False
        if not self.left or not self.right:
            return True
        if self.left.val == 0 and self.right.val == 0:
            return False
        if self.left.can_insert() or self.right.can_insert():
            return True
        return False

    def inorder_tree(self):
        global inorder_array
        if self.left and self.left.val != 0:
            self.left.inorder_tree()
        inorder_array.append(self.val)
        if self.right and self.right.val != 0:
            self.right.inorder_tree()

    def rewrite_tree(self):
        global sorted_array
        if self.val != 0:
            if self.left:
                self.left.rewrite_tree()
            self.val = sorted_array.pop(0)
            if self.right:
                self.right.rewrite_tree()

def construct_tree(array):
    head = BST()
    for element in array:
        head.insert(element)
    return head

def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1

def quick_sort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quick_sort(array, low, pi - 1)
        quick_sort(array, pi + 1, high)

def get_paths_util(curr_node, sum_so_far, path):
    if not curr_node:
        return
    sum_so_far += curr_node.val
    path.append(curr_node.val)
    if sum_so_far == S:
        paths.append(path[:])
    if curr_node.left and curr_node.left.val != 0:
        get_paths_util(curr_node.left, sum_so_far, path)
    if curr_node.right and curr_node.right.val != 0:
        get_paths_util(curr_node.right, sum_so_far, path)
    path.pop(-1)

def get_paths(node):
    if not node:
        return
    path = []
    get_paths_util(node, 0, path)
    if node.left:
        get_paths(node.left)
    if node.right:
        get_paths(node.right)

filename = ("input_10b.txt")
S = int(input("Enter the value of S: "))

with open(filename) as file:
    data = file.read().split(" ")
    array = [int(element) for element in data]

head = construct_tree(array)
inorder_array = []
head.inorder_tree()
sorted_array = inorder_array[:]
quick_sort(sorted_array, 0, len(sorted_array) - 1)
head.rewrite_tree()

paths = []
get_paths(head)

output_filename = ("output.txt")
with open(output_filename, "w") as output_file:
    for line in paths:
        output_file.write(" ".join(str(node) for node in line) + '\n')
