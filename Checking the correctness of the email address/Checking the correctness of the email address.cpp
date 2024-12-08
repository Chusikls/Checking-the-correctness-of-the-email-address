#include <iostream>
int findPosition(std::string email) {
    for (int n = 0; n < email.size(); n++) {
        if (email[n] == '@') {
            return n;
        }
    }
    return 0;
}
bool firsPartSize(int size) {
    if (size == 0 || size > 64) {
        return false;
    }
    return true;
}
bool secondPartSize(std::string email) {
    if (email.size() > 127) {
        return false;
    }
    return true;
}
bool firstPartSymbols(std::string email) {
    for (int n = 0; email[n] != '@'; n++) {
        if (email[n] < '!' || email[n] > '~' || email[n] == '(' || email[n] == ')' || email[n] == '@' || email[n] == ',' ||
            email[n] == ':' || email[n] == ';' || email[n] == '<' || email[n] == '>' || email[n] == '[' || email[n] == 92 ||
            email[n] == ']'){
            return false;
            }
    }
    return true;
}
bool secondPartSymbols(std::string email, int size) {
    for (int n = size + 1; n < email.size(); n++) {
        if ((email[n] > 'A' || email[n] < 'Z') || (email[n] > 'a' || email[n] < 'z') || email[n] == '-' || email[n] == '.') {
            return true;
        }
    }
    return false;
}
bool dotsRepetition(std::string email) {
    for (int n = 0; n < email.size() - 1; n++) {
        if (email[n] == '.' && email[n + 1] == '.') {
            return false;
        }
    }
    if ((email[0] == '.') && (email[email.size()] == '.')) {
        return false;
    }
    return true;
}
int main()
{
    int size;
    std::string email;
    std::cout << "Enter email: \n";
    std::cin >> email;
    size = findPosition(email);

    if (firsPartSize(size) == false || secondPartSize(email) == false || firstPartSymbols(email) == false ||
        secondPartSymbols(email, size) == false || dotsRepetition(email) == false) {
        std::cout << "No";
    }
    else std::cout << "Yes";
    
}

