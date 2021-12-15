import random
import csv
n = 500
m = 500
d = 25

skillsets = []
covered = []

rows, cols = (505, 500)
arr=[]
for i in range(rows):
    col = []
    for j in range(cols):
        col.append(0)
    arr.append(col)

for i in range(0,500):
    arr[0][i] = i+1

cache = []
for i in range(1,n+1):
    cache.append([])

for i in range(1,n+1):
    news = set()
    while len(news) != 25:
        news.add(random.randrange(0,m))
    skillsets.append(news)

for i in range(0,500):
    for z in skillsets[i]:
        cache[z].append(i)

cache.sort()

for i in range(0,500):
    for j in cache[i]:
        arr[i+1][j] = 1


with open('file.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerows(arr)
exit()


for i in range(0,m):
    covered.append(0)


having_most = {}

for i in range(0,n-1):
    having_most[i] = d

people_needed = 0

while min(covered) == 0:
    people_needed = people_needed + 1
    max_key = max(having_most, key=having_most.get)
    for e in skillsets[max_key]:
        covered[e] = 1
    having_most[max_key] = 0 

print(people_needed)




