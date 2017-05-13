//
//  main.cpp
//  concurrency_lesson1
//
//  Created by FrankLiu on 2017/5/13.
//  Copyright © 2017年 FrankLiu. All rights reserved.
//

#include <iostream>
#include <thread>
#include <vector>

void thread_function(){
    std::cout << "thread_function called!\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<std::thread> workers;
    for(int i = 0; i < 10; i++){
        workers.push_back(std::thread(thread_function));
    }
    for(std::vector<std::thread>::iterator iter = workers.begin(); iter != workers.end(); iter++){
        iter->join();
    }
    std::cout << "Hello, World!\n";
    return 0;
}
