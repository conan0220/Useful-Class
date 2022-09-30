import numpy as np
import matplotlib.pyplot as plt

import random
import data
import text as txt

lines = []


def preprocessData():
    text = txt.loadFile("input/text.txt")
    for line in text:
        if ("line" in line):
            dataOfLine = txt.numsFromString(line)
            lines.append(data.Line(data.Node(dataOfLine[0], dataOfLine[1]), data.Node(
                dataOfLine[2], dataOfLine[3])))


preprocessData()
x = []
y = []
for line in lines:
    x.append(line.n1.x)
    y.append(line.n1.y)
    x.append(line.n2.x)
    y.append(line.n2.y)

plt.plot(x, y)
plt.show()

# nodes = []
# lines = []
# for i in range(12):
#     nodes.append(data.Node(random.random(), random.random()))
# for i in range(len(nodes) - 1):
#     lines.append(data.Line(nodes[i], nodes[i + 1]))
# for line in lines:
#     print(line.n1.x, line.n2.x, line.length, sep=' ')
