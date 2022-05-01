import csv

filename = input()

required = 0
elective = 0
with open(filename) as c:
    reader = csv.DictReader(c, delimiter=',')
    for row in reader:
        if (row['Category'] == 'E' and not row['Grade'] == 'F'):
            elective += int(row['Credits'])
        elif (row['Category'] == 'R' and not row['Grade'] == 'F'):
            required += int(row['Credits'])

print("Required: %d" % required)
print("Elective: %d" % elective)
        
if required < 72 and elective < 28:
    print('N')
    print('Student still needs to complete %d required credits & %d elective credits for graduation.' % (72-required, 28-elective))
elif required < 72:
    print('N')
    print('Student still needs to complete %d required credits for graduation.' % (72-required))
elif elective < 28:
    print('N')
    print('Student still needs to complete %d elective credits for graduation.' % (28-elective))
else:
    print('Y')