//
//  main.cpp
//  STL_Learn
//
//  Created by FrankLiu on 2017/5/27.
//  Copyright © 2017年 FrankLiu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <clocale>

using namespace std;


int string_prePart(int argc, const char * argv[]) {
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
    int len = s3.length();
    cout << "len : " << len << endl;
    cout << "s3.empty() " << s3.empty() << endl;
    std::cout << "Hello, World!\n";
    
    
    return 0;
}

int main() {
    string strA ("UIPower");
    string strB("Hello World ");
    strB += strA;
    strB += '!';
    strB.append(" 123");
    strB.append("abcd", 2);
    strB.append("abcd", 2, 1);
    
    string strC("STLTest");
    strB.append(4, 'U');
    
        cout << strB << endl;
    int a = strB.compare(strC);
    cout << "strB.compare(strC) " << a << endl;
    cout << strC.compare(strB) << endl;
    
    cout << strA.substr(2, 5) << endl;
    
    size_t pos = strA.find("Po", 0);
    cout << "pos: " << pos << endl;
    cout << strA.find('P', 0) << endl;
    string strF = "Po";
    cout << strA.find(strF, 0) <<endl;
    cout << strA.substr(pos, strA.length() - pos + 1) << endl;
    
    if (strA.find("aa", 0) == -1){
        cout << "not found" << endl;
    }
    else {
        cout << "found" << endl;
    }
    printf("%d\n", strA.find("aa"));
    
    pos = strA.find("ow", 0);
    cout << pos << endl;
    
    strA.insert(1, "a");
    strA.insert(5, "a");
    cout << strA << endl;
    strA.insert(strA.length(), 5, 'I');
    cout << strA << "\tstrA.find('a', 0)" << strA.find("a", 0) <<'\t' <<  strA.rfind("a", strA.length()) << endl;
    
    strA.erase(2, 4);
    cout << strA << endl;
    
    strA.replace(2, strA.length() - 2 + 1, "A");
    cout << strA << endl;
    
    string strE = "UIPower";
    strF = "Hello";
    cout << strE << '\t' << strF << endl;
    strE.swap(strF);
    cout << strE << '\t' << strF << endl;
    
    
    return 0;
}
