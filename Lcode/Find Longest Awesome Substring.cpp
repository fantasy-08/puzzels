class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size(),ans=0;
        vector<int> mask(1<<10,-1);
        vector<int>count(10);
        mask[0]=-1;
        for(int i=0;i<n;i++){
            count[s[i]-'0']++;
            int temp=0;
            for(int j=0;j<10;j++){
                if(count[j]&1)temp|=(1<<j);
            }
            int req=0,chk=0;
            for(int j=0;j<10;j++){
                if((temp)&(1<<j))req|=(1<<j),chk++;
            }
            if(chk<=1){
                ans=max(ans,i+1);
            }
            else{
                if(mask[req]!=-1)ans=max(ans,i-mask[req]+1);//all zero
                for(int j=0;j<10;j++){
                    //jth bit is one and else zero
                    int Z=0;
                    if(temp&(1<<j)){
                        Z=req^(1<<j);
                    }else{
                        Z=req|(1<<j); 
                    }
                    if(mask[Z]!=-1)ans=max(ans,i-mask[Z]);
                }                
            }
            if(mask[temp]==-1)
                mask[temp]=i;
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};