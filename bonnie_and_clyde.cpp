#include <bits/stdc++.h>

using namespace std;

int U;
int V;
int W;
bool Q;
bool F;

int V_dfs(vector<vector<int>> &p, vector<char> &v, vector<char> &t, int j,  bool &f){
    if(j == W){
        f = true;
        cout << "YES"<<endl;
        return 0;
    }
    t[j] = 't';
    for(int n = 0; n < p[j].size(); n++){
        if(f)
            return 0;
        if(t[p[j][n]] == 'f'){
            Q = true;
            if(v[p[j][n]] == 'f'){
                if(p[j][n] == W){
                    f = true;
                    cout << "YES"<<endl;                
                    return 0;
                }                
                V_dfs(p ,v, t, p[j][n], f);
            }
        }
    }
    //v[j] = (j != U && j != V)?'f':'t';
    return 0;
}

int U_dfs(vector<vector<int>> &p, vector<char> &u, vector<char> &v, int i, bool &f){
    if(i == W){
        vector<char> t1(v.size(),'f');
        V_dfs(p, v, t1, V, f);
        return 0;
    }
    u[i] = 't';
    v[i] = 't';
    
    for(int n = 0; n < p[i].size(); n++){
        if(f)
            return 0;
        if(F == true && Q == false)
            return 0;
        /*if(n)
            v[p[i][n-1]] = 'f';*/
        if(u[p[i][n]] == 'f'){
            if(p[i][n] == W){
                vector<char> t(v.size(),'f'); 
                F = true;
                V_dfs(p, v, t, V, f);
                if(f)
                    return 0;
                if(Q == false)
                    return 0;
                else{
                    Q = false;
                    F = false;
                }                    
                continue;
            }                
            U_dfs(p ,u, v, p[i][n], f);
        }
    }
    v[i] = 'f';
    return 0;
}

int main() {
    int n;
    int m;
    int q;
    cin >> n >> m >> q;
    vector<vector<int> > nodes(n+1);
    for(int a0 = 0; a0 < m; a0++){
        int u;
        int v;
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }    
    for(int a0 = 0; a0 < q; a0++){                
        cin >> U >> V >> W;
        if(U == V && V == W){
            cout << "YES" <<endl;
            continue;
        }
        if(U == V){
            cout << "NO" <<endl;
            continue;
        }
        
        vector<char> visit_1(n+1,'f');  
        vector<char> visit_2(n+1,'f');
        bool f = false;
        Q = false;
        F = false;
        visit_1[V] = (V != W)?'t':'f';;
        visit_2[U] = (U != W)?'t':'f';;        
        U_dfs(nodes, visit_1, visit_2, U, f);
        if(f == false){
            cout << "NO" <<endl;            
        }
    }
    return 0;
}
