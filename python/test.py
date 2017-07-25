import hou

n = hou.node("/")
print n

n1 = n.createNode("blur")
print n1.name()

n2 = n.createNode("blur")
print n2.name()

n3 = n.createNode("blur")
print n3.name()