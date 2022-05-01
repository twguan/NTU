import math
import csv

sum = 0
people = 0
filename = input()
with open(filename) as file:
    reader = csv.reader(file, delimiter=',')
    for row in reader:
        if row[0].isdigit():
            people += 1
            score = int(math.sqrt(int(row[1]))*11)
            if score > 100:
                score = 100
            sum += score
        
print('%.1f' % (sum / people))