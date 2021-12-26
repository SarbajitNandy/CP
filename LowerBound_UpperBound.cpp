#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// class Student
// {
// public:
// 	string name, std, dept;
// 	int roll;
// 	Student() {}

// 	Student(string n, string s, string d, int r)
// 	{
// 		name = n;
// 		std = s;
// 		dept = d;
// 		roll = r;
// 	}

// 	// void toString() {
// 	// 	cout << "Student [Name="<<stu->name << ", Std="<<stu->std << ",Dept="<<stu->dept << ", Roll="<< stu->roll <<"]";
// 	// }
// 	void toString()
// 	{
// 		cout << "Student [Name=" << name << ", Std=" << std << ",Dept=" << dept << ", Roll=" << roll << "]";
// 	}

// 	bool operator<(const Student &stu)
// 	{
// 		return this->roll < stu.roll;
// 	}
// };
template <typename T>
int l_bound(vector<T> &arr, const T& k) {
	int start = 0, end=arr.size(), mid;

	while(start!=end) {
		mid = (start+end)/2;
		if (arr[mid]<k) {
			start=mid+1;
		} else { end=mid;}
	}
	if (start==arr.size()) return -1;
	return start;
}
template <typename T>
int u_bound(vector<T> &arr, const T& k) {
	int start = 0, end=arr.size(), mid;

	while(start!=end) {
		mid = (start+end)>>1;
		if (arr[mid]<=k) {
			start=mid+1;
		} else { end=mid;}
	}

	if (start==arr.size()) return -1;
	return start;
}
int main()
{

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("error.txt", "w", stderr);

	// vector<int> arr = {5,2,1,4,3};

	// cout << arr[*(upper_bound(arr.begin(), arr.end(), 7))] << endl;

	// vector<Student> arr;
	// arr.push_back(Student("sarbajit", "1st", "CSE", 19));
	// arr.push_back(Student("shalmoli", "1st", "CSE", 20));
	// arr.push_back(Student("Supriya", "1st", "CSE", 21));
	// arr.push_back(Student("shuvankar", "1st", "CSE", 32));

	// sort(arr.begin(), arr.end());

	// for (Student it : arr)
	// {
	// 	it.toString();
	// 	cout << endl;
	// }


	/*
		Tutorial : lower_bound & upper_bound

			

	*/
	int val1,val2;
	vector<int> arr={1,2,4,5,6,6,6,6,7};
	int k=3;
	val1= u_bound(arr, k);
	val2 = upper_bound(arr.begin(), arr.end(), k) - arr.begin();

	cout << val1 << "  " << val2 << endl;

	assert(val1==val2);

	assert(u_bound(arr,k)-l_bound(arr,k)==upper_bound(arr.begin(), arr.end(), k)-lower_bound(arr.begin(), arr.end(), k));

}