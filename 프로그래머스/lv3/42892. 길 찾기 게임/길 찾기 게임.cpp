#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct tree_node {
    int left_child; 
    int right_child; 
    int parent; 
    int x,y;
};

bool comp(vector<int> a, vector<int> b)
{
    if (a[1] > b[1]) return true; 
    if (a[1] == b[1]) {
        if (a[0] > b[0]) return false;
        else return true; 
    }
    else return false; 
}

void preorder(vector<tree_node> &tree, vector<int> &ans, int root) {
    ans.push_back(root);
    if (tree[root].left_child != -1) {
        preorder(tree,ans,tree[root].left_child);
    }
    if (tree[root].right_child != -1) {
        preorder(tree,ans,tree[root].right_child);
    }
}

void postorder(vector<tree_node> &tree, vector<int> &ans, int root) {
    if (tree[root].left_child != -1) {
        postorder(tree,ans,tree[root].left_child);
    }
    if (tree[root].right_child != -1) {
        postorder(tree,ans,tree[root].right_child);
    }
    ans.push_back(root);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int n = nodeinfo.size();
    
    for (int i=0; i<n; i++) nodeinfo[i].push_back(i+1); // 인덱스 추가 
    
    sort(nodeinfo.begin(), nodeinfo.end(), comp);
    
    vector<tree_node> tree(n+1); 
    int root = nodeinfo[0][2];
    
    tree[root].parent = -1;
    tree[root].left_child = -1;
    tree[root].right_child = -1; 
    tree[root].x = nodeinfo[0][0];
    tree[root].y = nodeinfo[0][1]; 
    
    for (int i=1; i<n; i++) {
        int child = nodeinfo[i][2]; // 자식이 될 노드 인덱스 
        int index = root;
        for (; ;) {
            if (tree[index].x > nodeinfo[i][0]) {
                if (tree[index].left_child == -1) {
                    tree[index].left_child = child;
                    tree[child].parent = index;
                    tree[child].x = nodeinfo[i][0]; 
                    tree[child].y = nodeinfo[i][1]; 
                    tree[child].left_child = -1;
                    tree[child].right_child = -1;
                    break;
                }
                index = tree[index].left_child;
            }
            else if (tree[index].x < nodeinfo[i][0]) {
                if (tree[index].right_child == -1) {
                    tree[index].right_child = child; 
                    tree[child].parent = index;
                    tree[child].x = nodeinfo[i][0]; 
                    tree[child].y = nodeinfo[i][1]; 
                    tree[child].left_child = -1;
                    tree[child].right_child = -1;
                    break;
                }
                index = tree[index].right_child;
            }
        }
    }
    
    // for (int i=1; i<=n; i++) {
    //     cout << i << " " << tree[i].left_child << " " << tree[i].right_child << endl;
    // }
    vector<int> ans;
    
    preorder(tree,ans,root);
    answer.push_back(ans);
    
    ans.clear();
    
    postorder(tree,ans,root);
    answer.push_back(ans);

    return answer;
}