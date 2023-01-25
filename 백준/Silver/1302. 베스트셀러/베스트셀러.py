import sys
input = sys.stdin.readline

n = int(input())
book = {}
for i in range(n) :
    temp = input().rstrip()
    if temp not in book :
        book[temp] = 1
    else :
        book[temp] = book[temp] + 1

book = dict(sorted(book.items()))
ans = []
c = max(book.values())
for i in book :
    if book[i] == c :
        print(i)
        break
