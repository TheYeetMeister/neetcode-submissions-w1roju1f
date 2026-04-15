class BinaryNode:
    def __init__(self, key, value):
        self._left = None
        self._right = None
        self._key = key
        self._value = value

    def setLeft(self, node):
        self._left = node
    
    def setRight(self, node):
        self._right = node

    def setKey(self, key):
        self._key = key

    def setVal(self, value):
        self._value = value
    
    def getVal(self):
        return self._value

    def getKey(self):
        return self._key

    def getLeft(self):
        return self._left

    def getRight(self):
        return self._right

class TreeMap:
    def __init__(self):
        self._root = None

    def insert(self, key: int, val: int) -> None:
        if self._root == None:
            self._root = BinaryNode(key, val)

        prev = None
        currNode = self._root

        while currNode:
            prev = currNode

            if currNode.getKey() > key:
                currNode = currNode.getLeft()
            elif currNode.getKey() < key:
                currNode = currNode.getRight()
            else:
                currNode.setVal(val)
                return

        if prev.getKey() > key:
            prev.setLeft(BinaryNode(key, val))
        else:
            prev.setRight(BinaryNode(key, val))

        

    def get(self, key: int) -> int:
        currNode = self._root

        while currNode:
            if currNode.getKey() > key:
                currNode = currNode.getLeft()
            elif currNode.getKey() < key:
                currNode = currNode.getRight()
            else:
                return currNode.getVal()

        return -1

    def getMin(self) -> int:
        if self._root == None:
            return -1

        currNode = self._root
        while currNode.getLeft():
            currNode = currNode.getLeft()

        return currNode.getVal()

    def getMax(self) -> int:
        if self._root == None:
            return -1

        currNode = self._root
        while currNode.getRight():
            currNode = currNode.getRight()

        return currNode.getVal()
    
    def removeHelper(self, curr, key) -> None:
        if curr == None:
            return None

        if key > curr.getKey():
            curr.setRight(self.removeHelper(curr.getRight(), key))
        elif key < curr.getKey():
            curr.setLeft(self.removeHelper(curr.getLeft(), key))
        else:
            if curr.getLeft() == None:
                return curr.getRight()
            elif curr.getRight() == None:
                return curr.getLeft()
            else:
                minNode = curr.getRight()
                while minNode.getLeft():
                    minNode = minNode.getLeft()
                
                curr.setKey(minNode.getKey())
                curr.setVal(minNode.getVal())
                curr.setRight(self.removeHelper(curr.getRight(), minNode.getKey()))
            
        return curr
        

    def remove(self, key: int) -> None:
        self._root = self.removeHelper(self._root, key)

    def getInorderKeys(self) -> List[int]:
        returnList = []

        currNode = self._root
        stack = []

        while currNode or stack:
            if not currNode:
                topNode = stack.pop()
                returnList.append(topNode.getKey())
                currNode = topNode.getRight()
                continue

            stack.append(currNode)
            currNode = currNode.getLeft()

        return returnList

