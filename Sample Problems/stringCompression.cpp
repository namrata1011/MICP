#include <bits/stdc++.h>
using namespace std;
int main(){
	string s,t;
	cin>>s;
	int len = s.length();
	char ch = s[0];
	t+=ch;
	int i=1,count=1;
	while (i<len) {
		
		if (ch==s[i]) {
			count++;
		}
		else {
			t+=('0'+count);
			ch = s[i];
			count=1;
			t+=ch;
		}
		i++;
	}
	t+=('0'+count);
	if (t.length()<s.length())
		cout<<t;
	else
		cout<<s;
	return 0;
}
