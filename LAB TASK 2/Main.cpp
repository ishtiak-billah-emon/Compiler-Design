#include <bits/stdc++.h>
#include <fstream>
#include <sstream>

using namespace std;

set<string>Var;
set<string>Key;
set<string>Op;
set<string>punctuation;
set<string>digit;


bool is_valid(string str){

    if( (str[0] >= 'a' and str[0] <= 'z' ) or (str[0] >= 'A' and str[0] <= 'Z') or (str[0] == '_')){

        for(int i = 1; i < str.size(); i++){
            if(str[i] == '$' or str[i] =='!',str[i] =='#', str[i] =='%'){
                return false;
            }
        }

        return true;
    }

    return false;

}

bool is_digit_valid(string str){

    int dot_count = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '.'){
            dot_count++;
        }
        
    }


    for(int i = 0; i < str.size(); i++){
        if( (str[i] >= '0' and str[i] <= '9') or (str[i] == '.')){
            
        }else{
            return false;
        }
    }

    if(dot_count <= 1 ){
        return true;
    }
    return false;

}

bool check_string(string word){

    int sz = word.size();
    char first = word[0];
    char last = word[sz -1];

    if(first == '"' and last == '"'){
        return true;
    }

    return false;

     
}

void final_check(string word){

    if(check_string(word)){

        digit.insert(word);
    }else{
        cout << "Error : \n" << word <<'\n';
    }




}

int main() {

    ifstream inputFile("inputf.in");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }


    ifstream secondFile("keywords.txt");
    if (!secondFile.is_open()) {
        cerr << "Error opening keyword file." << endl;
        return 1;
    }


    ifstream thirdFile("Operators.txt");
    if (!thirdFile.is_open()) {
        cerr << "Error opening operator file." << endl;
        return 1;
    }

    ifstream fourthFile("Punctuation.txt");
    if (!fourthFile.is_open()) {
        cerr << "Error opening Punctuation file." << endl;
        return 1;
    }


    set<string> keywordSet;
    set<string> operatorSet;
    set<string> punctuationSet;

    string line;


    while (getline(secondFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            keywordSet.insert(word);
        }
    }


    while (getline(thirdFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            operatorSet.insert(word);
        }
    }



    while (getline(fourthFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            punctuationSet.insert(word);
        }
    }

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (keywordSet.find(word) != keywordSet.end()) {
               // cout << "Found in Keyword: " << word << endl;
               Key.insert(word);


            } else if (operatorSet.find(word) != operatorSet.end()) {
        
                Op.insert(word);

            }else if(punctuationSet.find(word) != punctuationSet.end()){
  
                punctuation.insert(word);

            }else if(is_digit_valid(word)){

                    digit.insert(word);

            }else if(is_valid(word)){

                   Var.insert(word);
            }
            else{


                    final_check(word);
                    
                }
            }
        }
    

    cout << "KEYWORD LIST :\n";
    cout << "----------------------\n";
    for(auto x : Key){
        cout << x << ' ';
    }cout << '\n';
    cout << "----------------------\n";


    cout << "OPERATOR LIST :\n";
    cout << "----------------------\n";
    for(auto x : Op){
        cout << x << ' ';
    }cout << '\n';
    cout << "----------------------\n";


    cout << "PUNCTUATION LIST :\n";
    cout << "----------------------\n";
    for(auto x : punctuation){
        cout << x << ' ';
    }cout << '\n';
    cout << "----------------------\n";


    cout << "CONSTANT LIST :\n";
    cout << "----------------------\n";
    for(auto x : digit){
        cout << x << ' ';
    }cout << '\n';
    cout << "----------------------\n";


    cout << "IDENTIFIER LIST :\n";
    cout << "----------------------\n";
    for(auto x : Var){
        cout << x << ' ';
    }cout << '\n';
    cout << "----------------------\n";



    inputFile.close();
    secondFile.close();
    thirdFile.close();
    fourthFile.close();

    return 0;
}
