//
//  main.cpp
//  STL_Learn
//
//  Created by FrankLiu on 2017/5/27.
//  Copyright © 2017年 FrankLiu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    string s1(2, '1');
    string s2("abce");
    cout << s1 << endl;
    cout<< s2 << endl;
    
    s1 = "aaaabbcdedfa";
    char c = s1[3];// if s1[50] occur:越界错误
    try{
        c = s1.at(50); // 越界处理与[]不同；s1.at(50): throw exception :out_of_rang
    }
    catch (...){
        cout << "out_of_range" << endl;
    }
    cout << c << endl;
    
    s1[4] = 'x'; // call char &operator[](int n) rather than const char *operator[](int n) const;
    cout << s1 << endl;
    
    const char * ptr = s1.c_str();
    printf("%s\n", ptr);
    cout << ptr << endl;
    
    char e[8] = {0};
    size_t iCount = s1.copy(e, 7, 0);
    e[iCount] = '\0';
    cout << "e: " << e << endl;
    s1 = "UIPow";
    iCount = s1.copy(e, 3, 2);
    e[iCount] = '\0';
    cout << "e: " << e << endl;
    
    string s3;
    s3.assign(s1, 0, 2);
    cout << "s3: " << s3 << endl;
    s3.assign(3, 'c');
    cout << "s3: " << s3 << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
