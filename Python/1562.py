import sys

N = int(sys.stdin.readline())


number = 1 << 1
print(bin(number))
for i in range(2,10) :
    print(bin(number | 1 << (i + 1) ))
    print((number | 1 << (i + 1) ))



