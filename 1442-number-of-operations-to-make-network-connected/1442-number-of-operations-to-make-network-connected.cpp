class DisjointSet{
    public:
    vector<int>parent;
    vector<int>Size;
    DisjointSet(int n){
        parent.resize(n+1,0);
        for (int i = 0; i <= n; ++i) {
           parent[i] = i;
       }

        Size.resize(n+1,0);
    }



    int findUPar(int u ){ // 2->3->1.    
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findUPar(parent[u]);
    }

    void UnionBySize(int u, int v){
        int U_ultimateParent=findUPar(u);
        int V_ultimateParent=findUPar(v);

        if( U_ultimateParent== V_ultimateParent) return;

        if(Size[u]>Size[v]){
           parent[V_ultimateParent] = U_ultimateParent;
            Size[u]+=Size[v];
        }
        else{
            parent[U_ultimateParent] = V_ultimateParent;
            Size[v]+=Size[u];
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtraEdge=0;


        // count total co
        for(auto node:connections){
            int u=node[0];
            int v=node[1];
            // if ultimate parent is sam that means extra edge is there
            if(ds.findUPar(u)==ds.findUPar(v)){
                cntExtraEdge++;
            }
            else{
                ds.UnionBySize(u,v);
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if (ds.findUPar(i) == i) cnt++; 
        }
         int ans=cnt-1;
         cout<<"ans is "<<ans<<endl;
         cout<<"cnt Extras "<<cntExtraEdge<<endl;
         if(cntExtraEdge>=ans) return ans;
         return -1;
        
    }
};