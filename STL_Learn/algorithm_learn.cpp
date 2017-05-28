//
//  Deque_learn.cpp
//  STL_Learn
//
//  Created by FrankLiu on 2017/5/28.
//  Copyright © 2017年 FrankLiu. All rights reserved.
//

#include "Deque_learn.hpp"
#include <list>
#include <iostream>
#include <set>
#include <string>
#include <functional>
#include <map>
#include <algorithm>
#include <vector>
#include <ctime>
#include <numeric>



using namespace std;

void Run_list(){
    int iArray[] = {1, 3, 2, 3, 3, 3, 4, 3, 5, 3};
    list<int> lstInt(iArray, iArray + sizeof(iArray)/sizeof(iArray[0]));
    for(list<int>::iterator iter = lstInt.begin(); iter != lstInt.end(); iter ++ ){
        cout << *iter << '\t';
    }
    cout << endl;
    
    lstInt.remove(3);
    for(list<int>::iterator iter = lstInt.begin(); iter != lstInt.end(); iter++){
        cout << *iter << '\t';
    }
    cout << endl;
    
    lstInt.reverse();
    
    for(list<int>::iterator iter = lstInt.begin(); iter != lstInt.end(); iter++){
        cout << *iter << '\t';
    }
    cout << endl;
    
}

class Student{
public:
    string name;
    string id;
    
public:
    Student(string _name, string _id){
        name = _name;
        id = _id;
    }
    /*
    bool operator == (const Student &rhs) const{
        return (name == rhs.name) && (id == rhs.id);
    }*/
    
};

//functor used in container class
struct studentFunctor{
    bool operator()(const Student &left, const Student &right){
        return (left.id).compare(right.id) < 0;
    }
};

void Run_set(){
    //set<int, greater<int> > setInt;
    set<int, less<int> > setInt; // == set<int> setInt
    for(int i = 9; i >= 0; i--){
        setInt.insert(i+1);
    }
    setInt.insert(9);
    setInt.erase(10);
    setInt.insert(11);
    set<int>::iterator iter = setInt.find(9);
    cout << "*iter " << *iter << endl;
    set<int>::iterator iter_lower = setInt.lower_bound(9);
    cout << "setInt.lower_bound(9) = " << *iter_lower <<endl;
    
    set<int>::iterator iter_upper = setInt.upper_bound(9);
    cout << "setInt.upper_bound(9) = " << *iter_upper << endl;
    
    pair<set<int>::iterator, set<int>::iterator> range_item = setInt.equal_range(9);
    cout << *(range_item.first) << '\t' << *(range_item.second) <<endl;
    
    for(set<int>::iterator iter = setInt.begin(); iter != setInt.end(); iter++) {
        cout << *iter << '\t';
    }
    cout <<endl;
    
    set<Student, studentFunctor> students;
    students.insert(Student("aa", "01"));
    students.insert(Student("bb", "02"));
    
    for(set<Student>::iterator iter = students.begin(); iter != students.end(); iter++) {
        cout << iter -> name << " : " << iter->id << endl;
    }
    
    /*
    students.erase(Student("aa", "01"));
    for(set<Student>::iterator iter = students.begin(); iter != students.end(); iter++) {
        cout << iter -> name << " : " << iter->id << endl;
    }*/
    
    int x ;
    scanf("%d", &x);
    multiset<int, greater<int>> h;
    while(x != 0){
        h.insert(x);
        scanf("%d", &x);
    }
    /*
    while(!h.empty()){
        multiset<int>::iterator iter = h.begin();
        cout << *iter << '\t';
        h.erase(iter);
    }*/
    for(multiset<int>::iterator iter = h.begin(); iter != h.end(); iter++) {
        cout << *iter << '\t';
    }
    cout << endl;
    
}

void Run_map(){
    map<int, string> stu;
    pair<map<int, string>::iterator, bool> res = stu.insert(pair<int, string>(3, "aa"));
    cout << stu.size() << endl;
    //stu.erase(3);
    cout << stu.size() << endl;
    map<int, string>::iterator iter = stu.find(3);
    if (iter != stu.end()){
        cout << iter -> second << '\n';
    }
    stu.insert(make_pair(4, "bb"));
    stu[5] = "cc";
    
    iter = stu.lower_bound(4);
    cout << iter->first << endl;
    
    pair<map<int, string>::iterator, map<int, string>::iterator> pair = stu.equal_range(4);
    cout << pair.first->first << '\t' << pair.second->first << endl;
    
    multimap<int, string> stu_course;
    stu_course.insert(make_pair(12, "En"));
    stu_course.insert(make_pair(12, "Math"));
    stu_course.insert(make_pair(13, "En"));
    stu_course.insert(make_pair(13, "Math"));
    multimap<int, string>::iterator iter_ml = stu_course.find(13);
    while(iter_ml != stu_course.end()){
        cout << iter_ml->first << '\t' << iter_ml->second << endl;
        iter_ml ++;
    }
    
}
bool Great(int value, int threshold){
    return value > threshold ? true : false;
}
template <typename T>
void Out(T begin, T end){
    T iter;
    for(iter = begin; iter != end; iter++){
        cout << *iter << '\t';
    }
    cout << endl;
}
bool cmp(const int &a, const int &b) {
    return a > b ? true : false;
}
int myRandom(int i){
    return rand() % i;
}
void Run_algorithm() {
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(5);    cout << "vec original: ";
    Out(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    cout << "vec reverse: ";
    Out(vec.begin(), vec.end());
    
    vector<int>::iterator iter = adjacent_find(vec.begin(), vec.end());
    cout << *iter << endl;
    long n = count(vec.begin(),vec.end(), 2);
    cout << "2 count : " << n << endl;
    cout << "3 count : " << count(vec.begin(), vec.end(), 3) << endl;
    int threshold = 3;
    n = count_if(vec.begin(), vec.end(), [threshold](int x) -> bool {return x > threshold; });
    cout << "larger tha 4 : " << n << endl;
    
    vector<int>::iterator iter_find = find(vec.begin(), vec.end(), 4);
    cout <<"find 4 iterator: " <<  *iter_find << endl;
    vector<int>::iterator iter_find_if = vec.begin();
    cout << "find element that larger than 3 : ";
    while((iter_find_if = find_if(iter_find_if, vec.end(), [&threshold] (int x) -> bool {return x > threshold;})) != vec.end()){
        cout << *iter_find_if << '\t';
        iter_find_if ++;
    }
    cout << endl;
    
    vector<int> vecD;
    vecD.resize(vec.size());
    copy(vec.begin(), vec.end(), vecD.begin());
    
    cout << "vecD: ";
    Out(vecD.begin(), vecD.end());
    
    
    random_shuffle(vecD.begin(), vecD.end());
    cout << "vecD random_shuffle : ";
    Out(vecD.begin(),vecD.end());
    
    srand(unsigned(time(0)));
    random_shuffle(vecD.begin(), vecD.end(), myRandom);
    
    
    vecD.insert(vecD.begin() + 1, 1);
    cout << "vecD random_shuffle with srand: ";
    Out(vecD.begin(), vecD.end());
    
    //replace(vecD.begin(), vecD.end(), 1, 10);
    replace_if(vecD.begin(), vecD.end(), [threshold](int x){return x > threshold ? true : false;}, 9);
    cout << "replace 1 with 9:  ";
    Out(vecD.begin(), vecD.end());
    
    
    
    
    
    set<int> setA;
    setA.insert(2);
    setA.insert(1);
    setA.insert(5);
    bool search = binary_search(setA.begin(), setA.end(), 3);
    cout << "search_3: " << search << endl;
    search = binary_search(setA.begin(), setA.end(), 5);
    cout << "search_5: " << search << endl;

    
    vector<int> vecB({3, 1, 5, 7, 9});
    vector<int> vecC;
    sort(vec.begin(), vec.end(), [](const int &a ,const int &b) -> bool {return a > b ? true : false; });
    sort(vecB.begin(), vecB.end(),[](const int &a, const int &b) -> bool {return a > b ? true : false;});
    cout << "Out vec: ";
    Out(vec.begin(), vec.end());
    cout << "Out vecB: ";
    Out(vecB.begin(), vecB.end());
    vecC.resize(vec.size() + vecB.size());
    
    //merge(vec.begin(), vec.end(), vecB.begin(), vecB.end(), vecC.begin()); // will sort two input sorted vec.
    merge(vec.begin(), vec.end(), vecB.begin(), vecB.end(), vecC.begin(), cmp);
    
    
    cout << "merge result: ";
    for(int i = 0;i < vecC.size(); i++) {
        cout << vecC[i] << '\t';
    }
    cout << endl;
    
}
void Out(string flag, vector<int> &vec){
    cout << flag;
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++){
        cout << *iter << '\t';
    }
    cout << endl;
}
template<typename T>
void show(const T x){
    cout << x << '\t';
}
void Run() {
    vector<int> vecA;
    vector<int> vecB;
    for(int i = 0; i < 10; i += 2) {
        vecA.push_back(i+1);
        vecB.push_back(i + 2);
    }
    vecB.push_back(1);
    vecB.push_back(3);
    vecB.push_back(2);
    cout << "vecA original value: ";
    Out(vecA.begin(), vecA.end());
    
    int sum = accumulate(vecA.begin(), vecA.end(), 0);
    cout <<"vecA accumulate is : " << sum << endl;
    
   // fill(vecA.begin(), vecA.end(), 77);
   // Out("fill value:", vecA);
    sort(vecB.begin(), vecB.end());
    sort(vecA.begin(), vecA.end());
    Out("sorted vecA: ", vecA);
    Out("sorted vecB: ", vecB);
    vector<int> vecC;
    vecC.resize(vecA.size() + vecB.size());
    fill(vecC.begin(), vecC.end(), 0);
    set_union(vecA.begin(), vecA.end(), vecB.begin(), vecB.end(), vecC.begin());
    Out("set_union: ", vecC);
    long num_union = count_if(vecC.begin(), vecC.end(),[](int x) {return x != 0 ? true: false;});
    cout << "num_union: " << num_union << endl;
    
    fill(vecC.begin(), vecC.end(), 0);
    set_intersection(vecA.begin(), vecA.end(), vecB.begin(), vecB.end(), vecC.begin());
    Out("set_intersection: " , vecC);
    
    fill(vecC.begin(), vecC.end(), 0);
    set_difference(vecA.begin(), vecA.end(), vecB.begin(), vecB.end(), vecC.begin());
    //Out("set_difference: ", vecC);
    for_each(vecA.begin(), vecA.end(), [](int x) { cout << x << '\t';});
    cout << endl;
    transform(vecA.begin(), vecA.end(), vecA.begin(), [](int x) -> int {return x + 1; });
    for_each(vecA.begin(), vecA.end(), show<int>);
    cout << endl;
    
    cout << "Hello World" << endl;
}
