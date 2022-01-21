
int cycle[100005],rec[100005],vis[100005],special[100005],child[100005],a[100005],indegree[100005];
class Solution {
public:
    
    int count=0;
    void findcycles(int i){
        vis[i]=rec[i]=1;
        if(i==a[a[i]]){
            return;
        }
        if(rec[a[i]]){
            int z=a[i],c=0;
            do{
                z=a[z];
                cycle[z]=1;
                c++;
            }while(z!=a[i]);
            count=max(count,c);
        }
        else if(vis[a[i]]){
            rec[i]=0;
            return;
        }
        else findcycles(a[i]);
        rec[i]=0;
    }
    int maximumInvitations(vector<int>& b) {
        int n=b.size();
        for(int i=0;i<n;i++){
            a[i]=b[i];
            child[i]=special[i]=cycle[i]=rec[i]=vis[i]=indegree[i]=0;
        }
        for(int i=0;i<n;i++){
            indegree[a[i]]++;
            if(i!=a[a[i]] and vis[i]==0) findcycles(i);
        }

        vector<int> start;
        for(int i=0;i<n;i++){
            if(i==a[a[i]])  special[i]=1;
            else if(indegree[i]==0) start.push_back(i);
        }
        for(auto i: start){
            int j=i,c=0;
            while(!special[j] and !cycle[j]){
                j=a[j];
                c++;
            }
            if(special[j])  child[j]=max(child[j],c);
        }
        int ans=0;
        for(int i=0;i<n;i++) if(special[i] and a[i]>i) ans+=child[i]+child[a[i]]+2;
        return max(ans,count);
    }
};
