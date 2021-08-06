int ternarySearch(vector<int>&a,int ele)
{
	int l=0,h=a.size()-1;
	while(l<=h)
	{
		int mid1=l+(h-l)/3;
		int mid2=h-(h-l)/3;
		
		if(a[mid1]==ele || a[mid2]==ele){
			//found
			return a[mid1]==ele ? mid1 : mid2;
		}
		
		if(a[mid1]>ele){
			h=mid1-1;
		}
		else if(a[mid2]<ele){
			l=mid2+1;
		}
		else{
			l=mid1+1,h=mid2-1;
		}
	}
	
	return -1;
}
