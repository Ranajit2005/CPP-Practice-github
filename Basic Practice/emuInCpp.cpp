#include<iostream>
using namespace std;

// enum week {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
//           0      1        2          3         4        5         6  // By default, the first enumerator (Monday) is assigned the value 0, and each subsequent enumerator is assigned a value that is one greater than the previous enumerator. So, in this case, Monday will be 0, Tuesday will be 1, Wednesday will be 2, and so on up to Sunday which will be 6.

enum State {ON = 1, OFF = 0};  // In this case, the enumerator ON is explicitly assigned the value 1, and OFF is assigned the value 0. So, ON will be 1 and OFF will be 0.


enum day {Sunday = 1, Monday, Tuesday = 5, Wednesday, Thursday = 10, Friday, Saturday};
//          1           2           5         6          10            11       12
// In this case, the enumerator Sunday is explicitly assigned the value 1. Monday will be assigned the value 2 (one greater than Sunday), Tuesday is explicitly assigned the value 5, Wednesday will be assigned the value 6 (one greater than Tuesday), Thursday is explicitly assigned the value 10, Friday will be assigned the value 11 (one greater than Thursday), and Saturday will be assigned the value 12 (one greater than Friday).

// same vaule in two enumerators will give a compilation error because enumerators must have unique values. If you try to assign the same value to two different enumerators, the compiler will not be able to distinguish between them, leading to a compilation error.


int main(){

    float f = 5, g = 10;
    enum {i=1, j=2, k=3};

    // printf("%d",f++);
    // printf("%d",j++);   // enum values are constant and cannot be modified, so this will cause a compilation error.

    // enum week today = Wednesday;
    // printf("%d",today);  // This will print the integer value corresponding to the enumerator Wednesday, which is 2.

    // for(int i = Monday; i <= Sunday; i++){
        // i = 0; i <= 6; i++  // This loop will iterate through the integer values of the enumerators from Monday to Sunday, which are 0 to 6.
        // printf("%d ",i);  // This will print the integer values of the enumerators from Monday to Sunday, which are 0 to 6.
    // }

    enum State s = ON;
    // printf("%d",s);  // This will print the integer value corresponding to the

    // enum temp {hot = 100, cold = 0, warm = 50} t;
    // printf("%d",t);  // Undefined / unpredictable output

    enum temp {hot = 100, cold = 0, warm = 50} t = hot;
    // printf("%d",t);  // This will print the integer value corresponding to the enumerator hot, which is 100.

    enum day d;

    printf("%d %d %d %d %d %d %d", Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday);  // This will print the integer values corresponding to the enumerators in the day enum. Sunday will be 1, Monday will be 2, Tuesday will be 5, Wednesday will be 6, Thursday will be 10, Friday will be 11, and Saturday will be 12.


    return 0;
}