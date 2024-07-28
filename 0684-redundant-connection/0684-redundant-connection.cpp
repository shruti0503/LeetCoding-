class DisjointSet{
    public:
    vector<int>parent, size;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
    }
    
    int findUltimateParent(int node){
        if(node==parent[node]) return node;
         // path compression
        return parent[node]=findUltimateParent(parent[node]);
    }

    bool findisParentEqual(int u, int v){
        return  findUltimateParent(u)==findUltimateParent(v);

       
    }

    void UnionBySize(int u, int v){
        int ulp=findUltimateParent(u);
        int vlp=findUltimateParent(v);
        if(ulp==vlp) return ;
        // attache smaller to laregr one

        if(size[ulp]<size[vlp]){
            parent[ulp]=vlp;
            size[vlp]+=size[ulp];

        }
        else{
            parent[vlp]=ulp;
            size[ulp]+=size[vlp];

        }
    }


};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);
        for(auto it:edges){
            if(ds.findisParentEqual(it[0], it[1])) return it;
            ds.UnionBySize(it[0], it[1]);
        }

        return {};
        


    }
};