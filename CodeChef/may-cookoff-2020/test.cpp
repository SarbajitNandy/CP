#include <bits/stdc++.h>
using namespace std;

bool compare_max_heap(int a, int b)
{
	return a < b;
}

bool compare_min_heap(int a, int b)
{
	return a > b;
}
int main()
{
	vector<int> v = {1, 2, 3, 4, 5};

	for (int x : v)
		cout << x << " ";
	cout << endl;

	vector<int> cp1 = v, cp2 = v;

	make_heap(cp1.begin(), cp1.end(), compare_max_heap);
	make_heap(cp2.begin(), cp2.end(), compare_min_heap);

	cout << "Max Heap";
	for (int x : cp1)
		cout << x << " ";
	cout << endl;

	cout << "Min Heap";
	for (int x : cp2)
		cout << x << " ";
	cout << endl;

	// while (cp1.front() != cp2.front())
	// {
	// 	// cout << "Max Heap";
	// 	// for (int x : cp1)
	// 	// 	cout << x << " ";
	// 	// cout << endl;

	// 	// cout << "Min Heap";
	// 	// for (int x : cp2)
	// 	// 	cout << x << " ";
	// 	// cout << endl;
	// 	// pop_heap(cp1.begin(), cp2.end());
	// 	// cp1.pop_back();
	// 	// pop_heap(cp2.begin(), cp2.end());
	// 	// cp2.pop_back();
	// }

	while (cp1.size() && cp2.size()) {
		pop_heap(cp1.begin(), cp1.end());
		pop_heap(cp2.begin(), cp2.end());
		cout << "cp1 " << cp1.back() << endl;
		cout << "cp2 " << cp2.back() << endl;
		cp1.pop_back(); cp2.pop_back();
	}

	// cout << cp1.front() << endl;
	// cout << "Max Heap";
	// for(int x: cp1) cout << x << " "; cout << endl;

	// cout << "Min Heap";
	// for(int x: cp2) cout << x << " "; cout << endl;
}