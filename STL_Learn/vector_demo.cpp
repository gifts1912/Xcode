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
#include <vector>
#include <list>

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

int stringv2() {
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

template <typename T>
class CMax{
public:
    CMax(T a, T b){
        max_a = a;
        max_b = b;
    }
    T GetMax(){
        return max_a > max_b ? max_a : max_b;
    }
private:
    T max_a;
    T max_b;
};

int template_demo(){
    CMax<int> cmax_int(2, 3);
    int v = cmax_int.GetMax();
    cout << v << endl;
    
    CMax<double> cmax_double(2.3, 5.7);
    cout << cmax_double.GetMax() << endl;
    
    CMax<char> cmax_char('a', 'b');
    cout << cmax_char.GetMax() << endl;
    return 0;
}

int vector_v1(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(9);
    vec.pop_back();
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++){
        cout << *iter << '\t';
    }
    cout << endl;
    
    vec[2] = 155;
    vec.at(3) = 177;
    vec.front() = 111;
    vec.back() = 199;
    for(size_t i = 0; i < vec.size(); i++){
        cout << vec[i] << '\t';
    }
    cout << endl;
    
    cout << vec.front() << endl;
    cout << vec.back() << endl;
    
    list<int> my_list;
    for(int i = 0; i < 5; i++){
        my_list.push_back(i + 1);
    }
    list<int>::iterator iter_list = my_list.begin();
    cout << *iter_list << '\t' << endl; //<< *(iter_list + 2) << endl; //list, set, multiset, map, multimap 无随机访问迭代器
    
    vector<int>::iterator iter = vec.begin();
    cout << *iter << '\t' << *(iter + 2) << endl; //vector , deque support random access iterator
    
    
    for(vector<int>::reverse_iterator iter = vec.rbegin(); iter != vec.rend(); iter++) {
        cout << *iter << '\t';
    }
    cout << endl;
    
    
    int iArray[] = {0, 1, 2, 3, 4};
    vector<int> vecIntA(iArray, iArray + 5);
    vector<int> vecIntB(vecIntA.begin(), vecIntA.end());
    for(vector<int>::iterator iter = vecIntB.begin(); iter != vecIntB.end(); iter++) {
        cout << *iter << '\t';
    }
    cout << endl;
    
    vector<int> vecIntC(3, 9);
    for(vector<int>::reverse_iterator iter = vecIntC.rbegin(); iter != vecIntC.rend(); iter++){
        cout << *iter << '\t';
    }
    cout << endl;
    
    vecIntC.assign(vecIntB.begin(), vecIntB.end());
    
    cout << vecIntC.size() << '\t' << vecIntC.empty() << endl;
    vecIntC.resize(20);
    cout << vecIntC.size() << '\t' << vecIntC.empty() << endl;
    
    vecIntC.insert(vecIntC.begin(), 100);
    vecIntC.insert(vecIntC.begin() + 10, 4, 555);
    for(vector<int>::iterator iter = vecIntC.begin(); iter != vecIntC.end(); iter++){
        cout << *iter << '\t';
    }
    cout << endl;
    cout << vecIntC.size() << '\t' << vecIntC.empty() << endl;

    vector<int> vecA;
    for(int i = 1; i <= 9; i+=2){
        vecA.push_back(i);
    }
    
    vector<int> vecB;
    for(int i = 2; i <= 8; i+=2 ){
        vecB.push_back(i);
    }
    cout << "vecA: ";
    for(size_t i = 0; i < vecA.size(); i++) {
        cout << vecA[i] << '\t';
    }
    cout << endl;
    cout << "vecB: ";
    for(size_t i = 0;i < vecB.size(); i++){
        cout << vecB[i] << '\t';
    }
    cout << endl;
    vecA.insert(vecA.begin(), vecB.begin(), vecB.end());
    for(vector<int>::iterator iter = vecA.begin(); iter != vecA.end(); iter++) {
        cout << *iter << '\t';
    }
    cout << endl;
    vecA.erase(vecA.begin(), vecA.begin() + vecB.size());
    vecA.erase(vecA.begin());
    for(vector<int>::iterator iter = vecA.begin(); iter != vecA.end(); iter++) {
        cout << *iter << '\t';
    }
    cout << endl;
    
    vecA.clear();
    cout << vecA.empty() << endl;
    return 0;
}

int main(){
    int iArray[] = {1, 2, 3, 3, 4, 3, 6, 3};
    vector<int> vecA(iArray, iArray + sizeof(iArray)/sizeof(iArray[0]));
    vector<int>::iterator iter;
    cout << "Original value: ";
    for(iter = vecA.begin(); iter != vecA.end(); iter++) {
        cout << *iter << '\t';
    }
    cout << endl;
    for(iter = vecA.begin(); iter != vecA.end();) {
        if(*iter == 3){
            iter = vecA.erase(iter);
        }
        else{
            iter ++;
        }
    }
    cout << "New value: ";
    for(iter = vecA.begin(); iter != vecA.end(); iter++) {
        cout << *iter << '\t';
    }
    cout << endl;
    return 0;
}
