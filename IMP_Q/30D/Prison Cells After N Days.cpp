class Solution {
public:
    vector<int> nextDay(vector<int>days)
    {
        vector<int>nextD(8,0);
        for(int i=1;i<=6;i++)
        {
            if(days[i-1]==0 && days[i+1]==0)nextD[i]=1;
            else if(days[i-1]==1 && days[i+1]==1)nextD[i]=1;
        }
        return nextD;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(N <1)return cells ;
        map<vector<int>,int>m;
        map<int,vector<int>>mi;
        m[cells]=1;
        int Day=2;
        mi[1]=cells;
        int iniDays=N;
        while(N--)
        {
            vector<int>C=nextDay(cells);
            cells=C;
            // for(int i=0;i<8;i++)cout<<C[i]<<" ";
            // cout<<endl;
            if(m.find(C)!=m.end())
            {
                // cout<<"repeated "<<Day<<" matches with "<<m[C]<<endl;
                //N is left->iniDays+1-N
                //element=Day-m[C];
                int k=(iniDays+1-Day)%(Day-m[C]);
                cout<<k<<endl;
                return mi[k+m[C]];
                break;
            }
            else
            {
                mi[Day]=C;
                m[C]=Day++;                
            }
        }
         return cells;
        
    }
};
// 0 1 0 1 1 0 0 1 1
// 0 1 1 0 0 0 0 0 
// 0 0 0 0 1 1 1 0 3
// 0 1 1 0 0 1 0 0 
// 0 0 0 0 0 1 0 0 
// 0 1 1 1 0 1 0 0 
// 0 0 1 0 1 1 0 0 
// 0 0 1 1 0 0 0 0 
// 0 0 0 0 0 1 1 0 
// 0 1 1 1 0 0 0 0 
// 0 0 1 0 0 1 1 0 
// 0 0 1 0 0 0 0 0 
// 0 0 1 0 1 1 1 0 
// 0 0 1 1 0 1 0 0 
// 0 0 0 0 1 1 0 0 
// 0 1 1 0 0 0 0 0 16
// rep 16 matches with 2
