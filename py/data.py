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


class Arc:
    def __init__(self, begin, end, center, clockwise):
        self.begin = begin
        self.end = end
        self.center = center
        self.clockwise = clockwise
        self.radius = math.sqrt((begin.x - center.x) ** 2 + (begin.y - center.y) ** 2)
        self.beginAngle = calculateDegree(center, begin)
        self.endAngle = calculateDegree(center, end)
        if self.beginAngle == self.endAngle:
            self.endAngle += 360
        if self.clockwise == False:
            temp = self.beginAngle
            self.beginAngle = self.endAngle
            self.endAngle = temp

def calculateDegree(center, n):
    x = n.x - center.x;
    y = n.y - center.y;
    z = math.sqrt(x * x + y * y);
    angle = round(math.asin(abs(y) / z), 4)

    if angle == 0 and x == 0:
        angle = round(math.pi / 2, 4)
    if x >= 0 and y >= 0:             # first quadrant
        angle = angle
    elif x < 0 and y >= 0:         # second quadrant
        angle = math.pi - angle
    elif x < 0 and y < 0:         # third quadrant
        angle += math.pi
    elif x >= 0 and y < 0:        # forth quadrant
        angle = 2 * math.pi - angle
    return angle / math.pi * 180