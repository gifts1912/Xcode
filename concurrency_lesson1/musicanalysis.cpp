#include<iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int cmp(const pair<string, int> &pre, const pair<string, int> &pos){
	return pre.second <= pos.second;
}

template<typename T1, typename T2>
struct less_second{
	typedef pair<T1, T2> type;
	bool operator() (const type &v1, const type &v2){
		return v1.second <= v2.second;
	}

};

int main(){
	map<string, int> key_idx;
	int idx = 0;
	string line;
	while(getline(cin, line)){
		key_idx[line] = idx++;	
	}

	cout << "original contents in map: " << endl;
	for(map<string, int>::iterator iter = key_idx.begin(); iter != key_idx.end(); iter++){
		cout << iter->first << " : " << iter->second << '\t';
	}
	cout << endl;
	
	vector<pair<string, int> > vec(key_idx.begin(), key_idx.end());
	//sort(vec.begin(), vec.end(), cmp);
	sort(vec.begin(), vec.end(), less_second<string, int>());

	cout << "sorted contents in map: " << endl;
	for(vector<pair<string, int> >::iterator iter = vec.begin(); iter != vec.end(); iter++){
		cout << iter->first << " : " << iter->second << '\t';
	}
	cout << endl;

	return 0;

}


/*

using namespace std;
template <typename T1, typename T2>
struct less_second {
	    typedef pair<T1, T2> type;
		    bool operator ()(type const& a, type const& b) const {
				        return a.second < b.second;
						    }
};

map<string, int> mymap;
// 
//
// vector<pair<string, int> > mapcopy(mymap.begin(), mymap.end());
// sort(mapcopy.begin(), mapcopy.end(), less_second<string, int>());
*/
