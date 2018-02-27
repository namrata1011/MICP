/*
Problem: Word Break

Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words.
For example, consider the following dictionary: { pear, salmon, foot, prints, footprints, leave, you, sun, girl, enjoy },

Examples:
Given the string “youenjoy”, 
Output: True (The string can be segmented as “you enjoy”)

Input: “youleavefootprints”,
Output: True (The string can be segmented as “you leave footprints” or “you leave foot prints”)

Input:salmonenjoyapples
Output: False

#### TEBOW IT #####

T- Talk

Input?
- String and list of words

case sensitivity?
- No

Exception handling?
- if string is empty?
- if list is empty?

Multiple Existence of a word?

E - Examples

Test				String		Dictionary				Output
Empty string		""			["an","apple"]			True
Empty Dict			"anapple"	[]						False
Words Present 		"my"		["my","pen"]			True
Case sensitivity	"My"		["my","pen"]			false
Words not present	"mypen"		["my","pencil"]			False
Matching prefix		"pencilpen" ["pen", "pencil"]		True
Multiple Existence	"penpen"	["pen", "pencil"]		True

B - Brute Force

Algo a. 
1. Traverse the string from 0 to its length, n
2. Check if you have the current substring (obtained so far) in the dictionary:
	if yes, clear the substring.
	if no, continue ot check until the string ends.
	[This method will not work for 'Matching Prefix' case]

O- Optimize
	
ALgo b. 
1. Sort the dictionary words according to their lengths in decreasing order
2. Iterate these list of words:
	2.1 continue until the length of current word is greater than than the length of the given string.
	2.2 Check if the current word is a substring of given string.
		if yes, remove that substring from the given string
		if no, continue
		[In confusing case, it will clear "pencil" before "pen", and hence the output will be True.]
	2.3 Repeat this process until the list is completely iterated OR the string is empty.
3. If the string is empty, return True.
	else return False.
TC: O(mlogm) where m is the size of the dictionary


*/

#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
	return a.length() > b.length();
}

int wordBreak(string s, string w[], int n){
	if (n==0 || s=="") return -1;
	int i=0;
	while(w[i].length() > s.length() && i<n) i++;
	if (i==n) return 0;
	
	while(i<n && s!="") {
		//find if w[i] is present in s
		if (!w[i].empty())
			while (s.find(w[i])!= string::npos) {
				//remove that substr from s
				size_t posn = s.find(w[i]);
				int l = w[i].size();
				s.erase(posn,l);
			}
		i++;
	}
	
	if (s=="") return 1;
	return 0;
}

bool test(string w[],int n) {
	if (wordBreak("", w, n)!=-1) return false; //null case
	if (wordBreak("youleavefootprints", w, n)!=1) return false; //words present
	if (wordBreak("heyyou", w, n)!=0) return false; //words not present
	if (wordBreak("penpen", w, n)!=1) return false; //multiple existence
	if (wordBreak("pencilpen", w, n)!=1) return false; //matching prefix
	if (wordBreak("Pen", w, n)!=0) return false; //case sensitivity
	return true;
}

int main(){
	string w[] = { "pencil", "pen", "pear", "salmon", "foot", "prints", "footprints", "leave", "you", "sun", "girl", "enjoy" };
	int n=sizeof(w)/sizeof(w[0]);
	sort(w, w+n, compare);
	string input;
	cin>>input;
	cout<<wordBreak(input, w,n)<<endl;
	cout<<test(w,n);
	return 0;
}
