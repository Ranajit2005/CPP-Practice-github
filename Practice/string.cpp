#include<iostream>
#include<string>

using namespace std;
int main(){
    string str;
    str = "Ranajit Dey";
    // str = "kbjek";
    string str1("Bittu");
    cout<<str<<endl<<str1<<endl;

    // string st;
    // cin>>st;
    // getline(cin,st);
    // cout<<st<<endl;

    string rd;
    rd = "QWERTYUIOPASDFGHJKZXCVBNM";
    // reverse(rd.begin(),rd.end());
    cout<<rd.substr(1)<<endl;

    return 0;
}

// package com.company;

// public class cwh_21_ch5_loops {
//     public static void main(String[] args) {
//         System.out.println(1);
//         System.out.println(2);
//         System.out.println(3);

//         System.out.println("Using Loops:");
//         int i = 100;
//         while(i<=200){
//             System.out.println(i);
//             i++;
//         }
//         System.out.println("Finish Running While Loop!");

// //        while(true){
// //            System.out.println("I am an infinite while loop!");
// //        }
//     }
// }
