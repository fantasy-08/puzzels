// God & me
// Fly ...
//sort stack 
stack<int>s;
void sort()
{
	if(S.empty())return ;
	int S=s.top();
	sort();
	Insert(S);	
}
void Insert(int n)
{
	if(s.empty())
	{
		s.push(n);
		return ;
	}
	if(n>s.top())s.push(n);
	else
	{
		int t=s.top();
		Insert(n);
		s.pus(t);
	}
	return ;
}
