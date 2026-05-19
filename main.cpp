#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> keywords = {
    "int", "main", "cout", "endl",
    "return", "using", "namespace", "include"
};

bool isKeyword(string s) {
    for (const string& key : keywords) {
        if (s == key)
            return true;
    }
    return false;
}

bool isNumber(string s) {
    for (char c : s) {
        if (!isdigit(c))
            return false;
    }
    return !s.empty();
}

void classifyToken(string token) {
    if (token.empty()) return;

    if (isKeyword(token))
        cout << token << " --> Keyword" << endl;
    else if (isNumber(token))
        cout << token << " --> Number" << endl;
    else
        cout << token << " --> Identifier" << endl;
}

int main() 
{
    ifstream file("C:\\Users\\Acer\\Downloads\\sajj\\input.txt");

    if (!file) {
        cout << "Error: input.txt not found!" << endl;
        return 1;
    }

    cout << "=== File Content ===\n";

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.clear();
    file.seekg(0);

    cout << "\n=== Tokens & Classification ===\n";

    char ch;
    string buffer;

    string symbols = "(){};,<>=\"#";

    while (file.get(ch)) {

        if (symbols.find(ch) != string::npos) {

            classifyToken(buffer);
            buffer.clear();

            cout << ch << " --> Symbol/Operator" << endl;
        }

        else if (isspace(ch)) {

            classifyToken(buffer);
            buffer.clear();
        }

        else {
            buffer += ch;
        }
    }

    // Process last token if file ends
    classifyToken(buffer);

    file.close();

    return 0;
}