#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream &operator <<(ostream &os, const vector<T> v) {
	os << "{";
	for (typename vector<T>::const_iterator iter = v.begin(); iter != v.end(); iter++)
		os << *iter << (iter+1 != v.end() ? ", " : "");
	os << "}";
	return os;
}

template <typename T>
bool contains(const vector<T> &v, const T &val) {
	for (typename vector<T>::const_iterator iter = v.begin(); iter != v.end(); iter++)
		if (val == *iter) return true;
	return false;
}

int main() {
	cout << boolalpha;

	vector<int> vi;

	for (int i = 0; i < 10; i++)
		vi.push_back(i);

	cout << vi << endl;

	cout << "contains(5): " << contains(vi, 5) << endl;
	cout << "contains(10): " << contains(vi, 10) << endl;


	for (vector<int>::reverse_iterator riter = vi.rbegin(); riter != vi.rend(); riter++)
		cout << *riter << (riter+1 != vi.rend() ? ", " : "");
	cout << endl;

	return 0;
}
