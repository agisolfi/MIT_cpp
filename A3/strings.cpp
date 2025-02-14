#include <iostream>
#include <string>
using namespace std;

const string vowels = "aeiou";
string pigLatinify(string word) {
    if(word.find("qu")==0) {
        return word.substr(2,word.size()-2) + "-" + word.substr(0,2) + "ay";
    }
    else if(vowels.find(word[0]) != string::npos) {
        return word + "way";
    }
    else {
        return word.substr(1,word.size()-1) + "-" + word.substr(0,1) + "ay";
    }
}

int main() {
    string word = "test";
    cout<<pigLatinify(word);
}