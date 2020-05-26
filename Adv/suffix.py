class SuffixTree:
    def __init__(self,string):
        self.root={}
        self.endSymbol='*'
        self.populateString(string)
    def populateString(self,string):
        for i in range(len(string)):
            self.insertSubstring(i,string)
    def insertSubstring(self,i,string):
        node=self.root
        for i in range(i,len(string)):
            letter=string[i]
            if letter not in node:
                node[letter]={}
            node=node[letter]
        node[self.endSymbol]=True
    def search(self,string):
        node=self.root
        for i in range(len(string)):
            if string[i] not in node:
                return False
            node=node[string[i]]
        return self.endSymbol in node
##SUFFIX TREE##created