import data
import text as txt
import component as cpt
import render


def preprocessData():
    # read data and put it into components
    text = txt.loadFile("input/text.txt")
    presentComponent = "None"
    for line in text:
        if "assembly" in line and "assemblygap" not in line:
            presentComponent = "assembly"
            cpt.assemblies.append(cpt.Assembly())
        elif "copper" in line and "coppergap" not in line:
            presentComponent = "copper"
            cpt.coppers.append(cpt.Copper())
        elif "line" in line:
            dataOfLine = txt.numsFromString(line)
            newLine = data.Line(data.Node(dataOfLine[0], dataOfLine[1]), data.Node(
                dataOfLine[2], dataOfLine[3]))
            if presentComponent == "assembly":
                cpt.assemblies[-1].lines.append(newLine)
            if presentComponent == "copper":
                cpt.coppers[-1].lines.append(newLine)
        elif "arc" in line:
            dataOfLine = txt.numsFromString(line)
            newArc = data.Arc(data.Node(dataOfLine[0], dataOfLine[1]), data.Node(
                dataOfLine[2], dataOfLine[3]), data.Node(dataOfLine[4], dataOfLine[5]), "CCW" not in line)
            if presentComponent == "assembly":
                cpt.assemblies[-1].arcs.append(newArc)
            if presentComponent == "copper":
                cpt.coppers[-1].arcs.append(newArc)

preprocessData()
render.setFigure(pixel=100)
render.plot(cpt.assemblies, "black")
render.plot(cpt.coppers, "red")

render.show()
