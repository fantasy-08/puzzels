vector<int> parent;
vector<int> rnk;

void make_set(int n)
{
    parent.resize(n+1);
    rnk.resize(n+1,0);
    
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
}

int find(int u){
    if(parent[u]==u){
        return u;
        }
    return parent[u]=find(parent[u]);
}

void merge(int x,int y){
    x = find(x);
    y = find(y);
    
    if(rnk[x] > rnk[y]){
        parent[y] = x;
    }
    else{
        parent[x] = y;
    }
    if(rnk[x] == rnk[y]){
        rnk[y]++;
    }
}
bool compare(vector<int> &a, vector<int> &b){
return (a[2] < b[2]);
}
int Solution::solve(int A, vector<vector<int> > &B) {

sort(B.begin(),B.end(),compare);
make_set(A);
int count = 0;
int i = 0;
int cost = 0;
while(count != A-1){

      int par_u = find(B[i][0]);
      int par_v = find(B[i][1]);
      
      if( par_u != par_v ){
            count++;
            cost += B[i][2];      
            merge( par_u, par_v );
      }
    i++;
}
return cost;
}
