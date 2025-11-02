// #include<iostream>
// using namespace std;

// int main()
// {
//    char c = 'e';

//    if(c == 'a')
   
//      cout<<"vowel";
   
//    else if(c == 'e')
   
//     cout<<"vowel";
   
//    else if(c == 'i')
   
//     cout<<"vowel";
   
//    else if(c == 'o')
   
//     cout<<"vowel";
   
//    else if(c == 'u')
   
//     cout<<"vowel";
   
//    else
   
//     cout<<"consonent";
   
//    return 0;
// }



#include <iostream>
using namespace std;

int main()
{
    char c = 'd';

    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
       c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
    {
        cout << "vowel";
    }
    else
    {
        cout << "consonant";
    }

    return 0;
}
