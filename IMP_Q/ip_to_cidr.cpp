// https://leetcode.com/problems/ip-to-cidr/description/

#include <bits/stdc++.h>
using namespace std;

int getIpToMask(string ip) {
	int ipV = 4;
	int start = 0;
	unsigned int ipInInt = 0;
	while(ipV--) {
		int pos = ip.find('.', start);
		unsigned int mask = stoi(ip.substr(start, pos-start));
		ipInInt = (ipInInt << 8) | mask;
		start = pos+1;
	}
	return ipInInt;
}

string getIpFromMask(unsigned int ip, int lz)
{
	string ipStr = "";
	int ipV = 4;
	int maskBit = 32;
	while(ipV--) {
		maskBit-=8;
		int part = (ip >> maskBit) & 255;
		ipStr += to_string(part);
		if (ipV > 0) {
			ipStr += ".";
		} else {
			ipStr += "/";
		}
	}
	return ipStr + to_string(32-lz);
}

vector<string> getIpRange(string ip, int range) {
	unsigned int ipMask = getIpToMask(ip);
	vector<string> ipRange;

	while(range > 0) {
		int commonPrefix = __builtin_ctz(ipMask);
		if ((1<<commonPrefix) > range) {
			commonPrefix = __builtin_ctz(range);
		}
		ipRange.push_back(getIpFromMask(ipMask, commonPrefix));
		range-=(1<<commonPrefix);
		ipMask += (1<<commonPrefix);
	}

	return ipRange;
}


int main()
{
	unsigned int mask = getIpToMask("255.0.0.7");
	string ip = getIpFromMask(mask, 0);

	for(auto v: getIpRange("255.0.0.7", 10)) {
		cout<<v<<" ";
	}

	return 0;
}
