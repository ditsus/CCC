numOfStreams = int(input())
streams = []
input1 = 0

for i in range(numOfStreams):
	streams.append(int(input()))

while input1 != 77:
	input1 = int(input())
	if input1 == 99:
		splitStreamNum = int(input()) - 1
		leftFlowPercent = int(input()) / 100
		streams.insert(splitStreamNum, streams[splitStreamNum] * leftFlowPercent)
		streams[splitStreamNum + 1] *= 1 - leftFlowPercent
	if input1 == 88:
		joinStreamNum = int(input()) - 1
		streams[joinStreamNum + 1] += streams[joinStreamNum]
		del(streams[joinStreamNum])
 
for i in streams:
	print(int(i), end = " ")
