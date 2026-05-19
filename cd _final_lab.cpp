#include <iostream>
#include <string>
#include <vector>

bool isAccepting(char state) {
    return (state == 'C' || state == 'E');
}

char getNextState(char state, char input) {
    switch (state) {
        case 'A':
            if (input == 'a') return 'B';
            if (input == 'b') return 'C';
            break;
        case 'B':
            if (input == 'a') return 'B';
            if (input == 'b') return 'D';
            break;
        case 'C':
            if (input == 'a') return 'E';
            if (input == 'b') return 'C';
            break;
        case 'D':
            if (input == 'a') return 'E';
            if (input == 'b') return 'C';
            break;
        case 'E':
            if (input == 'a') return 'E';
            if (input == 'b') return 'C';
            break;
    }
    return 'X';
}

bool checkString(std::string str) {
    char current = 'A';
    for (char c : str) {
        current = getNextState(current, c);
        if (current == 'X') return false;
    }
    return isAccepting(current);
}

void processTest(std::string str) {
    if (checkString(str)) {
        std::cout << "Input: " << str << " | Result: Accepted" << std::endl;
    } else {
        std::cout << "Input: " << str << " | Result: Rejected" << std::endl;
    }
}

int main() {
    std::vector<std::string> testCases = {"b", "ba", "a", "ab", "abb"};
    for (const std::string& tc : testCases) {
        processTest(tc);
    }
    return 0;
}
