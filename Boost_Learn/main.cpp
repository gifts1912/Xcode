//
//  main.cpp
//  Boost_Learn
//
//  Created by FrankLiu on 2017/5/26.
//  Copyright © 2017年 FrankLiu. All rights reserved.
//

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <vector>
#include <fstream>
#include <string>

class Base {
public:
    virtual void Print(){
        std::cout << "Base is called!" << std::endl;
    }
};
class Derive: public Base{
public:
    void Print(){
        std::cout << "Derive is called!" << std::endl;
    }
};

void SharedPtr_01() {
    boost::shared_ptr<int> p1(new int(1));
    //shared_ptr uses a references counter internally. Only when boost::shared_ptr detects that the last copy of the smart pointer has been destroyed is the contained object released with delete.
    std::cout << *p1 << std::endl;
    boost::shared_ptr<int> p2{p1};
    p1.reset(new int{2}); // store a new value in current address; a new int object is anchored in p1, the existing int object is continues to exist, as it is anchored in p2; P1 is the sole owner of the int object with the number 2 and p2 is the sole owner of the int object with the number 1;
    std::cout << *(p1.get()) << '\t' << *p2 << std::endl; // get() retrieve the currently stored address.
    p1.reset();//will drop the refcount by one, if that results in the cout dropping to zero, the resource pointed to by the shared_ptr<> will be freed.
    
    std::cout << "Hello, World!\n";
    std::cout << static_cast<bool> (p1) << '\t' << static_cast<bool> (p2) << '\n';
}


int SharedPtr_02() {
    // insert code here...
    boost::shared_ptr<Base> p1(new Derive());
    p1->Print();
    
    boost::shared_ptr<Base> p2(new Base());
    p2->Print();
    boost::shared_ptr<Derive> p3 (new Derive());
    p3->Print();
    
    boost::shared_ptr<Base> ptr1 = p2; //assign construct results in counter add 1
    ptr1->Print();
    
    boost::shared_ptr<Base> ptr2(p2); // copy construct results in counter add 1
    ptr2->Print();
    
    std::cout << ptr2.use_count() << '\t' << p2.use_count() << std::endl;
    ptr2.reset(); // ptr2 pointer counter sub 1; then ptr2 pointer to NULL;
    std::cout << ptr2.use_count() << '\t' << p2.use_count() << '\t' << (ptr2.get() == NULL)<< std::endl;
    
    ptr2.reset(new Derive());
    ptr2->Print();
    
    return 0;
}

class Parent;
class Child;

class Parent{
public:
    Parent() {
        std::cout << "parent" << std::endl;
    }
    ~Parent(){
        std::cout << "Parent deconstrut is called!" << std::endl;
    }
    void fun(){
        std::cout << "fun is called!" << std::endl;
    }
    
public:
    //boost::shared_ptr<Child> child_ptr;
    boost::weak_ptr<Child> child_ptr;
    
};

class Child{
public:
    ~Child(){
        std::cout << "child deconstruct is called!" << std::endl;
    }
public:
    //boost::shared_ptr<Parent> parent_ptr;
    boost::weak_ptr<Parent> parent_ptr;
};



int weak_ptr_inLoop_ptr(){
    boost::shared_ptr<Parent> parent(new Parent);
    boost::shared_ptr<Child> child(new Child);
    parent -> child_ptr = child;
    child -> parent_ptr = parent;
    (child->parent_ptr).lock()->fun();// << std::endl; //lock() return shared_ptr;
    std::cout << "parent.use_count() " << parent.use_count() << std::endl;
    std::cout << "child.use_count() " << child.use_count() << std::endl;

    return 0;
}

class X{
public:
    X(){
        std::cout << "X..." << std::endl;
    }
    ~X(){
        std::cout << "X destroyed " << std::endl;
    }
    void Fun(){
        std::cout << "Fun" << std::endl;
    }
};

int weak_ptr_use_count(){
    boost::shared_ptr<X> p(new X());
    boost::weak_ptr<X> p2 = p; // doesn't change use_count of shared_ptr.
    std::cout << "weak_ptr p2.use_count() " << p2.use_count() << std::endl;
    std::cout << "shared_ptr p.use_count() " << p.use_count() << std::endl;
    {
        boost::shared_ptr<X> p3 = p2.lock(); //promote weak_ptr to shread_ptr
        std::cout<< "shared_ptr<X> p3.use_count() " << p3.use_count() << std::endl;
        boost::shared_ptr<X> p4 = p;
        std::cout << "weak_ptr p2.use_count() " << p2.use_count() << std::endl;
        std::cout << "shared_ptr p.use_count() " << p.use_count() << std::endl;
        p3->Fun();
    }
    std::cout << "weak_ptr p2.use_count() " << p2.use_count() << std::endl;
    std::cout << "shared_ptr p.use_count() " << p.use_count() << std::endl;
    return 0;
}

int shared_ptrAsVectorElements()
{
    std::vector<boost::shared_ptr<X> > vec;
    for(int i = 0; i < 20; i++){
        vec.push_back(boost::shared_ptr<X> (new X()));
    }
    for(std::vector<boost::shared_ptr<X> > ::iterator iter = vec.begin(); iter != vec.end(); iter++){
        boost::shared_ptr<X> tmp_ptr = *iter;
        //std::cout << iter->use_count() << std::endl;
        std::cout << tmp_ptr.use_count() << std::endl;
    }
    for(int i = 0; i < 20; i++){
        assert(vec[i].use_count() == 1);
    }
    
    return 0;
}
class FileProcess{
private:
    std::string file_name;
    std::fstream file_handle;
public:
    FileProcess(std::string fn){
        file_name = fn;
        std::cout << "Construct function is called!" << std::endl;
    }
    void fileOpen(){
        file_handle.open(file_name, std::fstream::in | std::fstream::out);
    }
    void fileRead(){
        std::string line;
        if(file_handle.is_open()){
            while(std::getline(file_handle, line)){
                std::cout << line << std::endl;
            }
        }
    }
    ~FileProcess(){
        file_handle.close();
        std::cout << "de construct function is called!" << std::endl;
    }
    
};

int main(){
    std::string fn = "/Users/frankliu/Projects/cplusplus/test.tsv";
    /*
    std::ifstream fr;
    fr.open(fn, std::fstream::in | std::fstream::out);
    if(fr.is_open()){
        std::string line;
        while(std::getline(fr, line)){
            std::cout << line << std::endl;
        }
        fr.close();
    }
    else{
        std::cout << "open failed!" << std::endl;
    }*/
    boost::shared_ptr<FileProcess> fp(new FileProcess(fn));
    boost::shared_ptr<FileProcess> fp2 = fp;
    fp2->fileOpen();
    fp2->fileRead();
    return 0;
}
