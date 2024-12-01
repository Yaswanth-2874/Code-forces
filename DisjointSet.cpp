#include <bits/stdc++.h>
using namespace std;

    class DisjointSet {
        vector<int> parent, size;
        public:
        DisjointSet(int n) {
            size.resize(n, 1);
            for(int i = 0; i < n; i++)
                parent.push_back(i);
        }
        int findParent(int node) {
            if(node == parent[node])
                return node;
            return parent[node] = findParent(parent[node]);
        }
        bool unionMerge(int nodeA, int nodeB) {
            int parentA = findParent(nodeA);
            int parentB = findParent(nodeB);

            if(parentA == parentB)
                return false;
            
            if(size[parentA] >= size[parentB]) {
                size[parentA] += size[parentB];
                parent[parentB] = parentA;
            } else {
                size[parentB] += size[parentA];
                parent[parentA] = parentB;
            }

            return true;
        }
        int findSize(int nodeA) {
            int parentA = findParent(nodeA);
            return size[parentA];
        }
    };
    
class DisjointSet2 {
    vector<int> parent;
    vector<int> ranks;
    vector<int> sizes;
    public:
    DisjointSet2(int n) {
        parent.resize(n+1); //for 1 based indexing
        ranks.resize(n+1, 0);
        sizes.resize(n+1, 1);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(node);//Path Compression
    }

    void unionByRank(int source1, int source2) {
        int parent1 = findParent(source1);
        int parent2 = findParent(source2);

        if(parent1 == parent2)
            return;
        if(ranks[parent1] > ranks[parent2])
            parent[parent2] = parent1;
        else if(ranks[parent2] > ranks[parent1])
            parent[parent1] = parent2;
        else {
            parent[parent1] = parent2;
            ranks[parent2]++;
        }
    }

    void unionBySize(int source1,int source2) {
        int parent1 = findParent(source1);
        int parent2 = findParent(source2);

        if(parent1 == parent2)
            return;
        
        if(sizes[parent1] > sizes[parent2]) {
            sizes[parent1] += sizes[parent2];
            parent[parent2] = parent1;
        } else {
            sizes[parent2] += sizes[parent1];
            parent[parent1] = parent2;
        }
    }

};