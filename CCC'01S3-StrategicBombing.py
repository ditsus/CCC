roads = []
roadInputs = ""
graph = {}

def bfs(graph, node, removedNode):
	visited = []
	queue = []

	visited.append(node)
	queue.append(node)

	while (queue):
		s = queue.pop(0)
		# print(s, end = " ")

		for n in graph[s]:
			if (s == removedNode[0] and n == removedNode[1] or s == removedNode[1] and n == removedNode[0]):
				x = 0
			else:
				if n not in visited:
					visited.append(n)
					queue.append(n)

	if ("B" not in visited):
		return(removedNode)
	else:
		return()

while (roadInputs != "**"):
	roadInputs = input()
	roads.append(roadInputs)
del(roads[-1])

for i in roads:
	if (i[0] in graph):
		graph[i[0]].append(i[1])
	else:
		graph[i[0]] = []
		graph[i[0]].append(i[1])
	if (i[1] in graph):
		graph[i[1]].append(i[0])
	else:
		graph[i[1]] = []
		graph[i[1]].append(i[0])

counter = 0

for i in roads:
	if (bfs(graph, "A", i) != ()):
		print(bfs(graph, "A", i))
		counter += 1

print(f"There are {counter} disconnecting roads.")
