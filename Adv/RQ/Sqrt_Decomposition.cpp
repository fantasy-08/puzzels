#inclde<bits/stdc+.h>
using namespace std;
#define N 1e4
#define B 1e2

int arr[N],block[B],blk_size;


void update(int idx,int val)
{
	int block_number=idx/blk_size;
	block[block_number]+=val;
	arr[idx]=val
}

int query(int l,int r)
{
	int sum=0;
	while(l<r && l%blk_size!=0 && l!=0)
	{
		sum+=arr[l++];	
	}
	while(l+blk_size<=r)
	{
		sum+=block[l/blk_size];
		l+=blk_size;
	}
	while(l<=r)
	{
		sum+=arr[l++];
	}
	return sum;
}

void preprocess(int input[],int n)
{
	int id_=-1;
	blk_size=sqrt(n);
	
	for(int i=0;i<n;i++)
	{
		arr[i]=input[i];
		if(i%blk_size)id_++;
		block[id_]+=arr[i]
	}
}
