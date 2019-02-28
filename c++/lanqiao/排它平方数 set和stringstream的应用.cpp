#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <sstream>
using namespace std;

set<char> st;

bool is_vaild(int n) {
    stringstream ss;
    string str;
    ss << n;
    ss >> str;
    for (int i = 0; i <= str.size(); i++) {
        if (st.count(str[i])) {
            return false;
        } else {
            st.insert(str[i]);
        }
    }
    return true;
}

bool is_vaild2(long long n) {
    stringstream ss;
    string str;
    ss << n;
    ss >> str;
    for (int i = 0; i < str.size(); i++) {
        if (st.count(str[i])) {
            return false;
        } 
    }
    return true;
}

int main() {
 for (int i = 102345; i <= 987654; i++) {
        if (is_vaild(i)) {
            long long k = i; //注意2个int相乘，还是结果int,会溢出
            long long tmp = k * k;
           
            if (is_vaild2(tmp)) {
                cout << i << " " << tmp <<endl;
            } 
        }
        st.clear();
    }
}