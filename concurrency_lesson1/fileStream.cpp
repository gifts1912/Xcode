#include<iostream>
#include<fstream>
#include <string>
#include <iterator>
#include <vector>
//#include <boost/algorithm/string.hpp>

using namespace std;

int main() {
	fstream fs;
	string line;
	/*
	fs.open("./feature.bat", ios::out | ios::in);
	while (getline(cin, line)) {
		if (line == "exit()")
			break;
		fs << line << endl;
	}
	fs.close();
	*/
	fs.open("./feature.bat", ios::in);
	cout << "fist time" << endl;
	while (!getline(fs, line).eof()) {
		cout << line << endl;
	}
	fs.clear();
	fs.seekg(0, fs.beg);
	/*
	cout << "after seekg(0, fs.beg);" << endl;
	while (getline(fs, line)) {
		cout << line << endl;
	}

	fs.clear();
	fs.seekg(0, fs.beg);
	istreambuf_iterator<char> isb(fs), end;
	string content(isb, end);

	cout << "second time" << endl;
	copy(content.begin(), content.end(), ostreambuf_iterator<char>(cout));


	cout << "third time" << endl;
	cout << content << endl;

	*/
	fs.seekg(0, fs.end);
	int length = fs.tellg();
	cout << "length of file is: " << length << endl;
	fs.seekg(0, fs.beg);
	char * buffer = new char[length];
	fs.read(buffer, length);
	delete[] buffer;
	

	ofstream ofile("./watch.tsv", ios::out);
	string cont((istreambuf_iterator<char>(fs)), (istreambuf_iterator<char>()));
	ofile.close();
	

	/*
	ostreambuf_iterator<char> osb(cout);
	istreambuf_iterator<char> isb(fs), end;
	while (isb != end) {
		*(osb++) = *(isb++);
	}
	*/
	
	fs.close();

	return 0;
}