int find(int* parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unite(int* parent, int* rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int minSwapsCouples(int* row, int rowSize) {
    int n = rowSize / 2;
    int parent[2 * n], rank[2 * n];
    
    for (int i = 0; i < 2 * n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    for (int i = 0; i < rowSize; i += 2) {
        int x = row[i] / 2;
        int y = row[i + 1] / 2;
        unite(parent, rank, x, y);
    }
    
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (find(parent, i) == i) {
            components++;
        }
    }
    
    return n - components;
}
