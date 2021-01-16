start = [int(x) for x in input().split(':')]
end = [int(x) for x in input().split(':')]
startmin = 60 * start[0] + start[1]
endmin = 60 * end[0] + end[1]
totmin = (startmin + endmin) // 2
minans = (totmin) % 60
hourans = (totmin) // 60
minans = str(minans)
hourans = str(hourans)
if (len(minans) == 1):
	minans = '0' + minans
if (len(hourans) == 1):
	hourans = '0' + hourans
print(hourans, ':', minans, sep = '')
