/*
Week 2 Problem: SUM3
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > threeSum(vector<int>& nums) {
        int n= nums.size();
//        cout<<n<<endl;
        vector<vector<int> > ans;
        if (n<3) return ans;
        
        sort(nums.begin(),nums.end());
        
        for (int i=0;i<n-2;i++) {
            if (i==0 || (i>0 && nums[i]!=nums[i-1])) {
                int j=i+1,k=n-1;

                while (j<k) {
                    if (nums[i]+nums[j]+nums[k]==0) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        ans.push_back(temp);

                        //to avoid duplicate triplets
                        while(j<k && nums[j]==nums[j+1]) j++;
                        while(j<k && nums[k]==nums[k-1]) k--;

                        j++; k--;
                    }
                    else if (nums[i]+nums[j]+nums[k]<0) 
                        j++;
                    else 
                        k--;
                }  
            }
        }
//        for (int i=0;i<ans.size();i++) {
//            for (int j=0;j<ans[i].size();j++) {
//                cout<<ans[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        return ans;
    }
    
//test cases
bool t2() {
	//All positives
	int arr[] = {1,2,3};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (threeSum(nums).size()!=0) return false;
}
bool t3() {
	//All negatives
	int arr[] = {-1,-2,-3};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (threeSum(nums).size()!=0) return false;
}
bool t4() {
	//All zeroes -> One triplet [0,0,0]
	int arr[] = {0, 0, 0, 0};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (threeSum(nums).size()!=1) return false;
}
bool t5() {
	//Only one triplet 
	int arr[] = {-1, 2, -1};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (threeSum(nums).size()!=1) return false;
}
bool t6() {
	//repeating elements
	int arr[] = {-1,0,1,2,-1,-4,-1,0,1,2,-1,-4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    if (threeSum(nums).size()!=2) return false;
}
    
bool test() {
	if (t2() && t3() && t4() && t5() && t6())
    return true;
}

int main(){
	int arr[] = {-1,0,1,2,-1,-4,};
	int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + n);
    
	vector<vector<int> > ans;
	//t1()
	if (n<3) {
		cout<<"Invalid Input.";
		return 0;
	}
	
    ans = threeSum(nums);
    if (ans.size()==0) {
    	cout<<"No triplets found.";
	}
	else {
		//printing the answer
		for (int i=0;i<ans.size();i++) {
            for (int j=0;j<ans[i].size();j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
	}
	
	test();
	
    return 0;
}
