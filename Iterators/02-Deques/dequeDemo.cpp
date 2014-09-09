#include <iostream>
#include <deque> 
#include <sstream>

using namespace std;


template <typename T>
ostream &operator <<(ostream &os, deque<T> &dq) {
	deque<T> hold;
        os << "[";
        while (!dq.empty()) {
                hold.push_back(dq.front());
                dq.pop_front();
                os << hold.back() << (!dq.empty() ? ", " : "");
        }
        os << "]";
        while (!hold.empty()) {
                dq.push_back(hold.front());
                hold.pop_front();
        }
        return os;
}

template <typename T>
bool contains(deque<T> dq, T val){
        bool check = false;
        deque<T> hold;
        for (typename deque<T>::const_iterator iter = dq.begin(); iter != dq.end(); iter++){
                if(dq.front() == val)
                        check = true;
                hold.push_back(dq.front());
                dq.pop_front();
        }
        for (typename deque<T>::const_iterator iter = dq.begin(); iter != dq.end(); iter++){
                dq.push_back(hold.front());
                hold.pop_front();
        }
        return check;
}

std::string asString (int x){
	string t;
	ostringstream oss;
	oss << x;
	t = oss.str();
	return t;
}


int main() {
        cout << boolalpha;

        deque<int> dqi;

        for (int i = 0; i < 20; i++)
                dqi.push_back(i);

        cout << dqi << endl;

        cout << "dqi contains 15: " << contains(dqi, 15) << endl;
        cout << "dqi contains 23: " << contains(dqi, 23) << endl;
      

	for (deque<int>::reverse_iterator riter = dqi.rbegin(); riter != dqi.rend(); riter++)
		cout << *riter << (riter+1 != dqi.rend() ? ", " : "");
	cout << endl;

 
        return 0;
}


