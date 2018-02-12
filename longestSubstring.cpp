/*
Problem: Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int longestSubstr(string s) {
	int len = s.length();
	string space = " ";
	
	if (len==0) return 0;
	
	if (s.find(space)!=string::npos) {
		return -1;
	}
	
	int max_len=1, temp_len=1, prev_visit;
	int last_visit[256];

	
	for (int i=0;i<256;i++) {
		last_visit[i]=-1;
	}
	last_visit[s[0]]=0;
	for (int i=1;i<len;i++) {
		prev_visit = last_visit[s[i]];
		
		if (prev_visit==-1 || i-prev_visit>temp_len) {
			temp_len++;
		}
		else {
			if (max_len<temp_len)
				max_len = temp_len;
			temp_len = i-prev_visit;
		}
		
		last_visit[s[i]]=i;
	}
	if (max_len<temp_len)
		max_len = temp_len;
		
	return max_len;
}

bool testFunc() {
	if (longestSubstr("")!=0) return false; //empty string
	if (longestSubstr("bbbb")!=1) return false; //repetitive characters
	if (longestSubstr("abcabcbb")!=3) return false; //sample testcase
	if (longestSubstr("pwwkew")!=3) return false; //non-repetitive characters
	if (longestSubstr("a12@#")!=5) return false; //special characters
	if (longestSubstr("Hi nam")!=-1) return false; //space character - treates as invalid
	if (longestSubstr("ABCabc")!=6) return false; //case sensitivity - valid
	
	return true;
}

int main() {
	string s;
	getline(cin,s);
	int res = longestSubstr(s);
	if (res==-1)
		cout<<"Invalid Input.";
	else
		cout<<res;
	cout<<endl;
	if (testFunc())
		cout<<"All tests passed.";
	else
		cout<<"Test case failed.";

	return 0;
}
