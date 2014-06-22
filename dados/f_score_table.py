old_table = open("old_f_score_table", "r")
new_table = open("f_score_table", "w")

new_table.write("10 100\n")

line = old_table.readline()
while (len(line) > 1):
	tokens = line.split()
	new_table.write(" ".join(tokens[1:len(tokens)]) + "\n")
	line = old_table.readline()
