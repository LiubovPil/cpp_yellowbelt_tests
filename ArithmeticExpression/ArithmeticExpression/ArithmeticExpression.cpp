// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>

using namespace std;

struct Operation {
    char operation = 0;
    int num = 0;
};

bool NeedBrackets(char& prev, char& next) {
    return (prev == '-' || prev == '+') && (next == '*' || next == '/');
}

int main()
{
    int number;
    cin >> number;
    
    deque<string> arith_express = {to_string(number)}; 

    int q;
    cin >> q;

    vector<Operation> operations(q);

    for (int i = 0; i < q; ++i) {
        cin >> operations[i].operation >> operations[i].num;

        if (i > 0 && NeedBrackets(operations[i - 1].operation, operations[i].operation)) {
            arith_express.push_front("(");
            arith_express.push_back(")");
        }

        arith_express.push_back(" " + string(1, operations[i].operation) + " " + to_string(operations[i].num));
    }
    for (const string& item : arith_express) {
        cout << item;
    }

    return 0;
}
