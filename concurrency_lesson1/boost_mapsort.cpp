/*************************************************************************
	> File Name: log_2.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Tue 23 May 2017 04:45:43 PM DST
 ************************************************************************/

#include<iostream>
#include <boost/algorithm/string.hpp>
#include <vector>

using namespace std;

int main(){
	string str_tmp = "aaa\thello world!\t123\tdd";
	cout << "original:" << str_tmp << ":" << endl;
	boost::trim_right(str_tmp);
	boost::trim_left(str_tmp);
	cout << "Trim_right:" << str_tmp << ":" << endl;
	vector<string> vec;
	boost::split(vec, str_tmp, boost::is_any_of("\t"));
	for(vector<string>::iterator iter = vec.begin(); iter != vec.end(); iter++){
		cout << *iter << " : ";
	}
	cout << endl;
	
	return 0;
}

/*
	tring line("test\ttest2\ttest3");
	vector<string> strs;
	boost::split(strs,line,boost::is_any_of("\t"));
	
	cout << "* size of the vector: " << strs.size() << endl;
	for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it)
	{
	    cout << *it << endl;
		}""""))"")out << "original: " << str_tmp << endl;
#include <boost/algorithm/string.hpp>

 std::string str("hello world! ");
 boost::trim_right(str);"")
	cout << "original: " << str_tmp << endl;
 */
