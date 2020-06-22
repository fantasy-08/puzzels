int arr[200005];
int tree[500005];

void build(int ind,int s,int e)
{
	if(s==e)
	{
		tree[ind]=arr[s];
		return;
	}
	int mid=s+(e-s)/2;
	build(2*ind,s,mid);
	build(2*ind+1,mid+1,e);
	tree[ind]=(tree[2*ind]+tree[2*ind+1]);
}

int query(int ind,int ss,int se,int qs,int qe)
{
	if(ss>=qs && se<=qe)
	{
		return tree[ind];
	}
	if(se<qs || ss>qe)return 0;
	int mid=ss+(se-ss)/2;
	int l=query(2*ind,ss,mid,qs,qe);
	int r=query(2*ind+1,mid+1,se,qs,qe);
	return (l+r);
}

void update(int ind,int ss,int se,int pos,int val)
{
	if(ss==se)
	{
		arr[pos]=val;
		tree[ind]=val;
		return ;
	}
	int mid=ss+(se-ss)/2;
	if(ss<=pos && pos<=mid)
		update(2*ind,ss,mid,pos,val);
	else
		update(2*ind+1,mid+1,se,pos,val);
	tree[ind]=tree[2*ind]+tree[2*ind+1];
}
