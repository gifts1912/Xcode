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
#include <sstream>

void thread_function(int i){
    std::ostringstream oss;
    oss << "thread_function called!" << i << "\n";
    std::cout << oss.str();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::ostringstream oss;
    std::vector<std::thread> workers;
    for(int i = 0; i < 10; i++){
        //workers.push_back(std::thread(thread_function, i));
        workers.push_back(std::thread([i](){
            std:: cout << "thread lambda function " << i << " \n";
        }));
    }
    /*
    for(std::vector<std::thread>::iterator iter = workers.begin(); iter != workers.end(); iter++){
        iter->join();
    }*/
    for_each(workers.begin(), workers.end(), [](std::thread &th){
        th.join();
    });
    std::cout << "Hello, World!\n";
    return 0;
}

