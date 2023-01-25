import sys
sudoku_field = []

blank_t = []

for i in range(9):
	sudoku_field.append(list(map(int, sys.stdin.readline().split())))
	for j in range(9):
		if sudoku_field[i][j] == 0:
			blank_t.append((i, j))

def update(num,y,x,sudoku) :
    for i in range(9) :
        if sudoku[y][i] == num :
            return 0

    for i in range(9) :
        if sudoku[i][x] == num :
            return 0

    r = 3*(y // 3) # 5면 3
    c = 3*(x // 3) # 4도 3
    for i in range(r,r+3) :
        for j in range(c,c+3) :
            if sudoku[i][j] == num :
                return 0
    return 1


def sudoku(field,blank_t,cnt):
    if cnt == len(blank_t):
        for i in range(9):
            for j in range(9):
                print(sudoku_field[i][j], end = ' ')
            print()
        exit(0)
    else:
        temp = 0
        n= blank_t[cnt][0]
        k =blank_t[cnt][1]
        for i in range(9) :
            temp = update(i+1,n,k,field)
            if temp == 1 :
                field[n][k] = i+1
                sudoku(field,blank_t,cnt+1)
                field[n][k] =0 

        
	
sudoku(sudoku_field,blank_t,0) 			

