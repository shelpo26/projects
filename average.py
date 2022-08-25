# average for loop

sum = 0
count = 0
print('before', count, sum)
for value in [9, 41, 12, 3, 74, 15] :
        count = count + 1
        sum = value + sum
        print(count, sum, value)
print ('after', count, sum, int(sum / count))