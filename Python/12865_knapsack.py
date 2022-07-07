import sys
N, K = map(int, sys.stdin.readline().split())

w = []
l = []

for i in range(N):
	a, b = map(int, sys.stdin.readline().split())
	w.append(a)
	l.append(b)

D = dict()
for i in range(N):
	if l[i] / w[i] not in D:
		D[l[i] / w[i]] = []
		D[l[i] / w[i]].append([l[i], w[i]])
	else:
	  D[l[i] / w[i]].append([l[i], w[i]])
	
d1 = sorted(D.items())
c = K
value = 0


max = 0
l = len(d1)
temp = []
x = []
y = []
t_w = []
flag = 0 
worth = []
count = 0

i = 0
j = 0

while i == 0 :
    k = i
    while k < l / 2:
        print("k",k)
        while j < len(d1[l-k-1][1]) :
            print("j: ",j)
            
            if  K >= d1[l-k-1][1][len(d1[l-k-1][1]) -j - 1][1] :
                K -= d1[l-k-1][1][len(d1[l-k-1][1]) - j - 1][1]
                temp.append(d1[l-k-1][1][len(d1[l-k-1][1])-j-1][1])
                t_w.append(d1[l-k-1][1][len(d1[l-k-1][1])-j-1][0])
                value += d1[l-k-1][1][len(d1[l-k-1][1]) - j - 1][0]
                print("value",value) 
                x.append(k)
                y.append(j)
                print("x :" ,x)
                flag = 0
                count += 1
            j = j + 1
        k = k + 1
        if max < value :
                max = value
        if k == l and len(y) != 0 and len(x) !=0 :
                K += temp.pop()
                value -= t_w.pop()
                k= x.pop()
                j = y.pop() + 1
                flag = 1
                continue
        j = 0

    i = i + 1
    
    K= c
    value = 0
        

if max < value :
        max = value
    
print(max)
