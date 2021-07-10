#include<bits/stdc++.h>
using namespace std;

int bsearch(string& s, int l, int r, int key){
    int index = -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(s[mid] <= key){
            r = mid - 1;
        } else {
            l = mid + 1;
                index = mid;
        }
    }
    return index;
}

void rev(string &s, int l, int r){
    while(l < r){
        swap(s[l], s[r]);
        l++;
        r--;
    }
}

bool next_permutation(string &s){
    int len = s.size();
    int i = len - 2;
    while(i >= 0 && s[i] >= s[i+1]){
        i--;
    }

    if(i < 0){
        return false;
    }

    int index = bsearch(s, i+1, len-1, s[i]);
    swap(s[i], s[index]);
    rev(s, i+1, len-1);
    return true;
}

int main(){
    string s = "rahul";
    bool p = next_permutation(s);
    if(p == false){
        cout << "Not Possible" << endl;
    } else {
        cout << s << endl;
    }
}
