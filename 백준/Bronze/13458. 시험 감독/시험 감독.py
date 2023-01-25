import sys

n = int(sys.stdin.readline())
people = list(map(int,sys.stdin.readline().split()))
b,c = map(int,sys.stdin.readline().split())

num = n
for i in range(n) :
    people[i] = people[i] - b # 최소 한명?
    if people[i] > 0 :
        if people[i] % c == 0 :
            num += int(people[i] / c)
        else :
            num += int(people[i] /c) + 1

print(num) 
