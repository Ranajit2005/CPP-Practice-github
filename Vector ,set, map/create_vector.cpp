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
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(10);
	for (int i = 0; i < v1.size(); i++){
		cout << v1[i] << endl;
	}
    
    int v,e;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;
    vector<int>vec[50];
    for(int i=0;i<e;i++){
        int a,b;
        cout<<"Enter which vertices are connected : ";
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    cout<<"The adjacence list is : "<<endl;

    for(int i=1;i<=v;i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }


	return 0;
}