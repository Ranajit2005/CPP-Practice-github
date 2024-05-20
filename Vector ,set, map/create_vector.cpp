#include <iostream>
using namespace std;

template <class t = int>
class vector{
	int *a;
	int capacity;
	int index;

public:
	vector(int n = 0){
		a = (t *)malloc(n * sizeof(t));
		capacity = n;
		index = 0;
	}

	int size(){
		return capacity;
	}

	void push_back(t value){
		capacity++;
		if (index + 1 == capacity){
			a = (t *)realloc(a, sizeof(t) * (capacity + 1));
		}
		a[index++] = value;
	}

	t operator[](int it){
		if (it < 0 || it > capacity - 1)
			exit(0);
		return a[it];
	}
};

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(5);
	v.push_back(10);
    vector<int>vec[10];
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
	return 0;
}