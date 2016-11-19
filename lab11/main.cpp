#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<fstream>
using std::ifstream;
#include<string>
using std::string;
#include<algorithm>
using std::copy;
#include<utility>
using std::pair;


size_t fill_array(long* (& ary), string f_name){
    ifstream ifs(f_name);
    long lon, cout;
    size_t sz = 0;
    
    ary = new int[lon];
    while (ifs >> lon){
        if (sz == 0){
            sz++;
            cout = lon;
            continue;
        }
        if (sz <= cout){
            ary[sz-1] = lon;
            // cout << ","<<ary[sz-1]<<endl;
            sz++;
        }
    }
    return sz;
}


void print_array(long* ary, size_t sz){
	// for (size_t a=0; a<sz; ++a){
	// 	cout << ary[a] << ':' << a << endl;
	// }
    // std::ostringstream out;
    copy(ary, ary+(sz), std::ostream_iterator<long>(cout, " "));
    // cout<<out.str()<<endl;
}


int main(){
    long *ary;
    size_t sz;
    pair<long*, size_t> p;
    sz = fill_array(ary, "tables.txt");
    print_array(ary, sz);
    cout << endl;
    // p = copy_evens(ary, sz);
    // print_array(p.first, p.second);
    // cout << endl;
    // add code to delete dynamic memory after this

}
