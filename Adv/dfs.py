class Node:
    def __init__(self,name):
        self.children=[]
        self.name=[]
    def add_child(self,name):
        self.children.append(Node(name))
        return self
    def dfs(self,array):
        array.append(self.name)
        for i in self.children:
            i.dfs(array)
        return array
result1 = []
test1 = Node("A")
test1.add_child("B").add_child("C")
test1.children[0].add_child("D")
print(test1.dfs(result1))
result2 = []
test2 = Node("A")
test2.add_child("B").add_child("C").add_child("D").add_child("E")
test2.children[1].add_child("F")
print(test2.dfs(result2))