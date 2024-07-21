N = int(input())
checked = []
dict = {}
freq1 = 0
freq1freq = 0
freq2 = 0
dele = []
diff = 0

for i in range(N):
	R = int(input())
	if (R not in dict):
		dict[R] = 1
	else:
		dict[R] += 1
	if (dict[R] > freq1):
		freq1 = dict[R]

for i in dict:
	if dict[i] == freq1:
		freq1freq += 1
	elif dict[i] > freq2:
		freq2 = dict[i]

if (freq1freq >= 2):
	for i in dict:
		if dict[i] == freq1:
			for j in dict:
				if dict[j] == freq1:
					if abs(i - j) > diff:
						diff = abs(i - j)
else:
	for i in dict:
		if dict[i] == freq1:
			for j in dict:
				if dict[j] == freq2:
					if abs(i - j) > diff:
						diff = abs(i - j)

print(diff)
