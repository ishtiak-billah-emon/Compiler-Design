#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void identify_Functions(ifstream& file) {
    set<string> functionSet;

    string line;
    while (getline(file, line)) {
        if (line.find("int ") != string::npos) {
            size_t pos = line.find("(");
            if (pos != string::npos) {
                string fName = line.substr(4, pos - 4);
                if(fName == "main"){
                    // then ignore. this is not user-defined function
                }else{

                    functionSet.insert(fName);
                }
                
            }
        }
    }

    while (getline(file, line)) {
        if (line.find("void ") != string::npos) {
            size_t pos = line.find("(");
            if (pos != string::npos) {
                string fName = line.substr(5, pos - 5);
                functionSet.insert(fName);
            }
        }
    }

    cout << "User-defined Functions:\n";
    int count = 0;
    for ( auto x : functionSet) {
        cout << "Function-" << ++count << ": " << x << "\n";
    }

    cout << "Total number of user-defined functions: " << functionSet.size() << "\n\n";


}

void Open_Program_File(){

    ifstream file("program.cpp");

    if (!file.is_open()) {
        cerr << "Error opening file!\n";
        return ;
    }

    identify_Functions(file);
    file.close();

}

int main() {

    Open_Program_File();

    return 0;
}
