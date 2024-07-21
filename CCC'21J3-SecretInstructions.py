numbers = 0
list1 = []

while numbers != "99999":
	numbers = input()
	list1.append(numbers)

del(list1[-1:])

for i in list1:
	sum = int(i[0]) + int(i[1])
	sum = str(sum)
	if sum == "0":
		print(f"{lastIns} {i[2:]}")
		
	elif int(sum[-1:]) % 2 == 0:
		print(f"right {i[2:]}")
		lastIns = "right"
	else:
		print(f"left {i[2:]}")
		lastIns = "left"
