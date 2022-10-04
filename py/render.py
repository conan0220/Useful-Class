from turtle import color
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches


def setFigure(pixel):
    plt.figure(dpi=pixel)

def plot(components, color="black"):
    ax = plt.subplot()
    for component in components:
        for line in component.lines:
            plt.plot([line.n1.x, line.n2.x], [line.n1.y, line.n2.y], color=color)       
        for arc in component.arcs:
            ax.add_patch(mpatches.Arc((arc.center.x, arc.center.y), arc.radius*2, arc.radius*2, theta1=arc.endAngle, theta2=arc.beginAngle, edgecolor=color))

def show():
    plt.show()
