#include <iostream>
#include<stack>
using namespace std;

/*class Stack
{
    int capacity;
    int *arr;
    int top;

public:
    Stack(int c)
    {
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int data)
    {
        if (this->top == capacity - 1)
        {
            cout << "Overfollow" << endl;
            return;
        }
        this->top++;
        arr[this->top] = data;
    }

    void pop()
    {
        if (this->top == -1)
        {
            cout << "Underfollow\n";
            return;
        }
        this->top--;
    }

    void peek()
    {
        cout << "The peek element is : " << arr[top] << endl;
        return;
    }

    void size()
    {
        cout << "The size is : " << top + 1 << endl;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack st(5);
    st.push(1);
    st.display();
    st.push(2);
    st.display();
    st.push(3);
    st.push(4);
    st.display();
    st.push(5);
    st.display();
    st.push(6);
    st.display();
    st.pop();
    st.display();
    st.size();
    st.peek();

    return 0;
}*/

int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    return 0;
}