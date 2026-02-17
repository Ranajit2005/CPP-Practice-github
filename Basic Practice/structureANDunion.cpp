#include<iostream>
using namespace std;


// --------------------------- Topic 1 ------------------------------
// In structure, the size is the sum of the size of all members. So, in this case, it will be 1 (for char) + 4 (for int) = 5 bytes. However, due to padding for alignment, the actual size may be larger (commonly 8 bytes on many systems).
struct demoS{
    char x;
    int y;
};

// In union, the size is the size of the largest member. So, in this case, it will be 4 bytes (the size of int), since int is larger than char.
union dempU{
    char x;
    int y;
};

// --------------------------- Topic 2 ------------------------------

union a{
    int x;
    char ch[2];
};

// ---------------------------- Topic 3 ------------------------------

struct num{
    int x;
};

// ----------------------------- Topic 4 ------------------------------

struct site{
    // char name[] = "ABC"; // This will cause a compilation error because you cannot initialize an array member directly in the struct definition.
    int a = 10; // This is allowed in C++11 and later, but it will be ignored in C++14. In C++14, you cannot initialize non-static data members directly in the struct definition. You would need to initialize them in a constructor or after creating an instance of the struct.
};

// In C++14, you cannot initialize non-static data members directly in the struct definition. You would need to initialize them in a constructor or after creating an instance of the struct.








int main(){
    // --------------------------- Topic 1 ------------------------------
    // demoS dS;
    // printf("Structure - > %d\n", sizeof(dS));
    // dempU dU;
    // printf("Union - > %d\n", sizeof(dU));

    // --------------------------- Topic 2 ------------------------------
    // a a1;    // This will create a union variable a1, but its members will contain garbage values until they are initialized.So
    a a1 = {};
    // a1.ch[0] = 3;
    // a1.ch[1] = 2;
    // cout << (int)a1.ch[0] << " " << (int)a1.ch[1] <<" "<<a1.x << endl;

    a1.ch[0] = 3;
    a1.ch[1] = 2;
    a1.x = 0; // This will overwrite the values in ch[0] and ch[1]
    // cout << (int)a1.ch[0] << " " << (int)a1.ch[1] <<" "<<a1.x << endl;


    // ---------------------------- Topic 3 ------------------------------
    num a,b;
    a.x = 5;
    b.x = 10;
    // int z = a + b; // This will cause a compilation error because you cannot directly add two struct variables.
    int c = a.x + b.x; // This will correctly add the members of the struct variables.
    // cout << c << endl;

    // ----------------------------- Topic 4 ------------------------------

    site s1;
    cout << s1.a << endl;

    return 0;
}