import sys

N = int(sys.stdin.readline())

student = list(map(int,sys.stdin.readline().split()))

# 링크드 리스트 구현 미숙해서 정답이 거꾸로 들어감 

class node :
    def __init__(self,data) :
        self.data = data
        self.next = None

class LinkedList :
    def __init__(self,data) :
        self.head = node(data)

    def insert_node(self,data,index) :
        new_node = node(data) 
        if index == 0 :
            new_node.next = self.head
            self.head = new_node
            return 
        cnt = 0
        cur_node = self.head
        while cnt < index -1 :
            if cur_node.next == None :
                break
            cnt += 1
            cur_node = cur_node.next
        
        temp = cur_node.next
        cur_node.next = new_node
        new_node.next = temp

    def make_list(self,arr) :
        cur = self.head
        while cur is not None :
            arr.append(cur.data)
            cur = cur.next 


ans = LinkedList(1)

for i in range(1,N) :
    ans.insert_node(i+1, student[i])

arr = [] 
ans.make_list(arr)

for i in range(N-1,-1,-1) :
    print(arr[i] , end= ' ') 
