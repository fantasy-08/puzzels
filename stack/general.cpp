// not tested yet!!

vector<int> nextGreater(vector<int>A){
        int n=A.size();
        vector<int>ans;
        stack<int>s;
        
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                ans[i]=-1;
            }else if(A[s.top()]>A[i]){
                ans[i]=s.top();
            }else if(A[s.top()] <= A[i]){
                while(!s.empty() && A[s.top()] <= A[i]){
                    s.pop();
                }
                
                if(!s.empty()){
                    ans[i]=s.top();
                }
            }
            
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
}

vector<int> prevGreater(vector<int>A){
        int n=A.size();
        vector<int>ans;
        stack<int>s;
        
        for(int i=0;i<n;i++){
            if(s.empty()){
                ans[i]=-1;
            }else if(A[s.top()]>A[i]){
                ans[i]=s.top();
            }else if(A[s.top()] <= A[i]){
                while(!s.empty() && A[s.top()] <= A[i]){
                    s.pop();
                }
                
                if(!s.empty()){
                    ans[i]=s.top();
                }
            }
            
            s.push(i);
        }
        
        return ans;
}

vector<int> prevSmaller(vector<int>A){
        int n=A.size();
        vector<int>ans;
        stack<int>s;
        
        for(int i=0;i<n;i++){
            if(s.empty()){
                ans[i]=-1;
            }else if(A[s.top()]<A[i]){
                ans[i]=s.top();
            }else if(A[s.top()] >= A[i]){
                while(!s.empty() && A[s.top()] >= A[i]){
                    s.pop();
                }
                
                if(!s.empty()){
                    ans[i]=s.top();
                }
            }
            
            s.push(i);
        }
        
        return ans;
}

vector<int> nextSmaller(vector<int>A){
        int n=A.size();
        vector<int>ans;
        stack<int>s;
        
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                ans[i]=-1;
            }else if(A[s.top()]<A[i]){
                ans[i]=s.top();
            }else if(A[s.top()] >= A[i]){
                while(!s.empty() && A[s.top()] >= A[i]){
                    s.pop();
                }
                
                if(!s.empty()){
                    ans[i]=s.top();
                }
            }
            
            s.push(i);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
}

// happy coding :)
