#include<iostream>
using namespace std;

class Stack{
    int t = -1;
    char* rd = new char[100];
public:
    void push(char r){
        t++;
        rd[t] = r;
    }
    char pop(){
        char r = rd[t];
        t--;
        return r;
    }
    char top(){
        return rd[t];
    }
    void Display(){
        for(int i=t;i>=0;i--){
            cout<<rd[i]<<" ";
        }
        cout<<endl;
    }
    bool empty(){
        if(t == -1)   return 1;
        return 0;
    }
}st;

int porio(char a){
    if(a == '^')    return 3;
    if(a == '*' || a == '/' || a == '%')    return 2;
    if(a == '+' || a == '-')    return 1;
    return -1;
}

void InfToPost(string s){
    string ans = "";
    for(int i=0; i<=s.size();i++){
        char ch = s[i];
        if(ch == '('){
            st.push(ch);
        }
        else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            ans.push_back(ch);
        }else if(ch == ')'){
            while(st.top()!='('){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^'){
            while(!st.empty() && porio(ch) < porio(st.top()) || !st.empty() && porio(ch)==porio(st.top()) ){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(ch);
        }
    }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    cout<<ans<<endl;
}

int main(){
    // Stack st;
    // st.push('a');
    // st.push('b');
    // st.push('c');
    // st.push('d');
    // st.Display();
    string rd = "((A-B)+D/(E+F)*G)";
    InfToPost(rd);
    return 0;
}