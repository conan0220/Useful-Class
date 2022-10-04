

assemblies = []
coppers = []


class Base:
    ASSEMBLY_GAP = None
    COPPER_GAP = None
    SILSCREEN_GAP = None

    def __init__(self, lines=None, arcs=None):
        self.lines = []
        self.arcs = []


class Assembly(Base):
    None


class Copper(Base):
    None
