import sys 
#메모리초과 -> 조건에 해당하는 리스트 생성 -> 입력값 인덱스 +1 
N = int(sys.stdin.readline())

n_list = [0] * 10001

for i in range(N) :
    n_list[int(sys.stdin.readline())] += 1 
    
for i in range(10001) :
    if n_list[i] > 0 : 
        for j in range(n_list[i]) :
            print(i)