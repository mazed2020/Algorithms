#include<bits/stdc++.h>
using namespace std;

vector<int> KMP(string p)
{
	int n = p.size();
	vector<int>LMP(n, 0);
	int i=1, j=0;

	while(i < n){
		if(p[i] == p[j]){
			++j;
			LMP[i++] = j;
		}
		else{
			if(j > 0)
				j = LMP[j-1];
			else
				i++;
		}
	}
	return LMP;
}

int Matching(string s, string p)
{
	int n = s.size(), m = p.size(), ans = 0;
	vector<int>LMP = KMP(p);

	int i=0, j=0;
	while(i < n){
		if(s[i] == p[j]){
			++i;
			++j;
		}
		if(j >= m){
			ans++;
			j = LMP[j-1];
		}
		else if(i < n && s[i] != p[j]){
			if(j > 0)
				j = LMP[j-1];
			else
				i++;
		}
	}
	return ans;
}

int main() {
	string s,p;
	cin>>p>>s;
	cout<<Matching(s, p)<<endl;
}
