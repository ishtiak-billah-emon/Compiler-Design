#include<bits/stdc++.h>
using namespace std;

bool is_constant(string s){


    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            //nothing to do
        }else{
            return false;
        }

    }

    return true;

}

int main(){

    string s; cin >> s;
    if(is_constant(s)){
        cout << "Its numeric constant\n";
    }else{
        cout << "Its not numeric constant\n";
    }

}

