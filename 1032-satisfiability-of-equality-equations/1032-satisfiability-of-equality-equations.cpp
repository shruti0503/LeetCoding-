class DisjointSet{
    public:
    vector<char>parent;
    DisjointSet(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    char findParent(char node){
        if(parent[node]==node) return node;

        return parent[node]=findParent(parent[node]);
    }

    void Union(char node1, char node2){
        char parentnode1=findParent(node1);
        char parentnode2=findParent(node2);

        if(parentnode1==parentnode2){
            return;
        }
        else{
           parent[node1]=parentnode2;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        //int n=equations
        DisjointSet ds(26);
        for(auto string:equations){
            if(string[1]=='='){
                char x=ds.findParent(string[0]-'a');
                char y=ds.findParent(string[3]-'a');
                if(x!=y){
                   ds.Union(x, y);
                }
            }
        }

        for(auto string:equations){
            if(string[1]=='!'){
                int x=ds.findParent(string[0]-'a');
                int y=ds.findParent(string[3]-'a');
                if(x==y){
                    return false;
                }
            }
        }

        return true;
        
    }
};