import math


class Node:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Line:
    def __init__(self, n1, n2):
        self.n1 = n1
        self.n2 = n2
        self.length = math.sqrt((n1.x - n2.x) ** 2 + (n1.y - n2.y) ** 2)
