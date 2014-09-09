#include <iostream>
#include <list>
#include <sstream>
#include <cstdlib>


using namespace std;

template <typename T>
ostream &operator <<(ostream &os, list<T> &l) {
	list<T> hold;
	bool isFirstElement = true;
	os << "[";

	/*while (!l.empty()) {
		hold.push_back(l.front());
		os << l.front() << (!l.empty() ? ", " : "");
		l.pop_front();
	}*/
	for (typename list<T>::const_iterator iter = l.begin(); iter != l.end(); iter++)
		cout << (isFirstElement ? (isFirstElement=false, "") : ", ") << *iter;
	os << "]";
	
	/*while (!hold.empty()) {
		l.push_back(hold.front());
		hold.pop_front();
	}*/
	
	return os;
}

template <typename T>
bool contains(list<T> l, T val){
       list<T> hold;
       for (typename list<T>::const_iterator iter = l.begin(); iter != l.end(); iter++)
		if (val == *iter) return true;
	
	return false;
       
}
 


std::string asString (int x){
	string t;
	ostringstream oss;
	oss << x;
	t = oss.str();
	return t;
}


template <typename T>
bool insertInOrder(list<T> &l, const T &val) {
	typename list<T>::iterator iter;
	for (iter = l.begin(); iter != l.end() && val >= *iter; iter++)
		;
	l.insert(iter, val);
	return false;
}

int main() {
	cout << boolalpha;

	list<int> li;

	for (int i = 0; i < 10; i++)
		insertInOrder(li, rand() % 100);

	cout << li << endl;
	
	cout << "li contains 15: " << contains(li, 15) << endl;
	cout << "li contains 23: " << contains(li, 23) << endl;
	
	cout << li << endl;	
	
	
	for (list<int>::reverse_iterator riter = li.rbegin(); riter != li.rend(); riter++){
		li.pop_front();
		cout << li << endl;
	}
	
	bool isFirstElement = true;
	for (list<int>::reverse_iterator riter = li.rbegin(); riter != li.rend(); riter++)
		cout << (isFirstElement ? (isFirstElement=false, "") : ", ") << *riter;
	cout << endl;
	
	return 0;
}

	
