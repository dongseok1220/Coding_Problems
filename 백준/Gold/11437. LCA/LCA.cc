#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void dfs(int node, int par, int dep, const vector<vector<int>>& tree, vector<vector<int>>& parent, vector<int>& depth) {
    parent[node][0] = par;
    depth[node] = dep;
    for (int child : tree[node]) { 
        if (child != par) { // 다른 경우 재귀적으로 직계 부모 찾음
            dfs(child, node, dep + 1, tree, parent, depth); 
        }
    }
}

// parent[node][j] = node의 2^j 번째 부모 
void preprocess(int n, vector<vector<int>>& parent, const vector<int>& depth) {
    int maxLog = log2(n) + 1;
    for (int j = 1; j < maxLog; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j - 1] != -1) { // node i의 2^(j-1)번째 부모가 존재한다면
                parent[i][j] = parent[parent[i][j - 1]][j - 1]; // parent[i][j-1]의 2^(j-1)번째 부모가 우리가 원하는 i의 2^j번째 부모가 된다. 
            }
        }
    }
}

int lca(int u, int v, const vector<vector<int>>& parent, const vector<int>& depth) {
    if (depth[u] < depth[v]) swap(u, v); // 깊이가 다르다면, 맞춰줘야함

    int log = log2(depth[u]); // u가 더 크니까

    for (int i = log; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) { // 1 << i = 2^i -> v보다는 커지지 않게 깊이 조정
            u = parent[u][i]; // u를 u의 2^i번째 부모로 업데이트 
        }
    }

    if (u == v) return u; // 동일하면 바로 반환 

    for (int i = log; i >= 0; i--) { // 다르다면 다시 같은 깊이에서 찾음 -> 이때 하나씩 내려가면서 찾음
        if (parent[u][i] != parent[v][i]) { 
            u = parent[u][i]; 
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int maxLog = log2(n) + 1;
    vector<vector<int>> parent(n + 1, vector<int>(maxLog, -1));
    vector<int> depth(n + 1);

    dfs(1, -1, 0, tree, parent, depth); // root 노드의 부모는 -1, 깊이 0 

    preprocess(n, parent, depth);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v, parent, depth) << "\n";
    }

    return 0;
}
