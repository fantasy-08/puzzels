
def toString(List): 
	return ''.join(List) 
x=[]
# Function to print permutations of string 
# This function takes three parameters: 
# 1. String 
# 2. Starting index of the string 
# 3. Ending index of the string. 
def permute(a, l, r): 
	if l==r: 
		x.append(toString(a)) 
	else: 
		for i in range(l,r+1): 
			a[l], a[i] = a[i], a[l] 
			permute(a, l+1, r) 
			a[l], a[i] = a[i], a[l] # backtrack 

# Driver program to test the above function 
string = "aaaabb"
n = len(string) 
a = list(string) 
permute(a, 0, n-1) 
x=list(set(x))
x.sort()
for i in x:
    print(i)
# // 0 is tree
# 1 0 0 0 1 0 0
1 -- 0 0 0 1 -- 1 1 0 0 1 -- 0 1 -- 1 0 0 1 -- 0 1 -- 0 0 1 -- 0 1 -- 1 1 1 0 1 -- 1 0 -- 1 