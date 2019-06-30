#include "CCharLikeStr.h"
#include <iostream>
using namespace std;

int main(){
    CCharLikeStr test_string;
    test_string.append((char*)"chenglongqiao");
    //printf("%s\r\n",test_string.c_str());
    //cout << "size is " << test_string.size() << endl;
    //test_string.append((char*)" is haoren");
    //printf("%s\r\n",test_string+(char*)("dddd"));
    //printf("%s\r\n",test_string.c_str());
    CCharLikeStr test_string2; 
    test_string2 = "i am a good boy";
    test_string2 = "dddddd";
    test_string2.append("cxxxxx");
    printf("is find: %d",test_string2.find("we"));
    printf("%s\r\n",test_string2.c_str());
    //string s = "sdfdsf";
    //cout << s <<endl;
    system("pause");
  
    return 0;
}