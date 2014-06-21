iris_data = open("iris.data", "r")
iris_cluster = open("iris_cluster.data", "w")

line = iris_data.readline()
iris_cluster.write(line)

line = iris_data.readline()
while (not line == "\n"):
	tokens = line.split()
	tokens[4] = "0"
	iris_cluster.write(" ".join(tokens) + "\n")
	line = iris_data.readline()
