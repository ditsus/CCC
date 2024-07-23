def check1(check):
	for l in range(1, int(TN[1])):
		if check[l] == check[l - 1]:
			return("F")
	return("T")

TN = input().split()

for i in range(int(TN[0])):
	string = input()
	check = []
	for j in range(int(TN[1])):
		if (string.count(string[j]) == 1):
			check.append(0)
		else:
			check.append(1)
	print(check1(check))
