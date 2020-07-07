class ListNode(object):
    def __init__(self,x):
        self.val=x
        self.next=None
        self.prev=None
class DLL(object):
    def __init__(self):
        self.head=None
        self.tail=None
    