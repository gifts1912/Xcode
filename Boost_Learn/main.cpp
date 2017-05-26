//
//  main.cpp
//  Boost_Learn
//
//  Created by FrankLiu on 2017/5/26.
//  Copyright © 2017年 FrankLiu. All rights reserved.
//

#include <iostream>
#include <boost/shared_ptr.hpp>

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


int main(int argc, const char * argv[]) {
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
