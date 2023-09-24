#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin >> s;
    char a[10];
    int array_index = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){

        }else{
            a[array_index] = s[i];
            array_index++;
        }

    }

   cout <<"Number of arithmetic operator  " << array_index << endl;
   for(int i = 0; i < array_index; i++){
    cout << a[i] << '\n';
   }



}

