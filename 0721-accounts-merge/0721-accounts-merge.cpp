class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1); // Each set starts with size 1
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i; // Each node is its own parent initially
        }
    }

    int findUPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionBySize(int node1, int node2) {
        int parent1 = findUPar(node1);
        int parent2 = findUPar(node2);
        if (parent1 == parent2) return;
        if (size[parent1] > size[parent2]) {
            parent[parent2] = parent1;
            size[parent1] += size[parent2];
        } else {
            parent[parent1] = parent2;
            size[parent2] += size[parent1];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;

        // Map each email to its account using union-find
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.UnionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // Group emails by their representative
        vector<vector<string>> mergedMail(n);
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
            
        }

        // Construct final result
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() > 0) {
                sort(mergedMail[i].begin(), mergedMail[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]); // Add account name
                for (auto mail : mergedMail[i]) {
                    temp.push_back(mail);
                }
                ans.push_back(temp);
            }
        }

        // Sort the final answer lexicographically
        sort(ans.begin(), ans.end());
        return ans;
    }
};
