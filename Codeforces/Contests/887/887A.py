s = input()

zeroes = 0
flag = 0

for x in s:
  if (x == '1'):
    flag = 1
  if (x == '0' and flag == 1):
    zeroes += 1

if (zeroes >= 6):
  print('yes')
else:
  print('no')