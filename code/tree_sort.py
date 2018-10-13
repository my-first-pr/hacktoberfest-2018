class BinaryTreeNode(object):
    #initial values for value,left and right
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


# inserting a new node in the binary tree
def insert(tree, item):
    # if no initial element in the tree
    if tree == None:
        tree = BinaryTreeNode(item)
    else:
        if (item < tree.value):
            # if left branch of the tree is empty
            if (tree.left == None):
                tree.left = BinaryTreeNode(item)
            else:
                insert(tree.left, item)
        else:
            # if right branch of the tree is empty
            if (tree.right == None):
                tree.right = BinaryTreeNode(item)
            else:
                insert(tree.right, item)
    return tree

# funtion for the inorder traversal of the binary tree
def in_order_traversal(tree,a):
    if (tree.left != None):
        in_order_traversal(tree.left,a)
    a.append(tree.value)
    if (tree.right != None):
        in_order_traversal(tree.right,a)


def tree_sort(x):
    # root node
    t = insert(None, x[0]);
    # inserting all elements in the binary tree
    for i in x[1:]:
        insert(t,i)
    # the results of the inorder traversal of a binary tree is a sorted
    a = []
    in_order_traversal(t,a)
    return a

