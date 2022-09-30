import nums_from_string as nfs


def loadFile(filePath):
    f = open(filePath, 'r')
    lines = f.readlines()
    f.close()
    return lines


def numsFromString(str):
    return nfs.get_nums(str)
