#include <iostream>
#include <cstring>
#define LGMAX 201
using namespace std;
bool cifra(char);
bool litera(char);
bool operand(char);
bool _operator(char);
bool parantezaDeschisa(char);
bool parantezaInchisa(char);
bool caracterNepermis(char);
bool evalExp(char*);
int main()
{
    char e[LGMAX];
    cout << "e = "; cin.getline(e, LGMAX);
    cout << evalExp(e);
    return 0;
}
bool evalExp(char* e)
{
    for (int i = 0; e[i]; i++)
    {
        if (caracterNepermis(e[i])) return 0;
        if (_operator(e[i]) && _operator(e[i+1])) return 0;
        if (_operator(e[i]) && i==0) return 0;
        if (_operator(e[i]) && parantezaDeschisa(e[i-1])) return 0;
        if (operand(e[i]) && operand(e[i+1])) return 0;
    }
    return 1;
}
bool caracterNepermis(char c)
{
    return !cifra(c) && !litera(c)
           && !operand(c) && !_operator(c)
           && !parantezaDeschisa(c) && !parantezaInchisa(c);
}
bool parantezaInchisa(char c)
{
    return c == ']' || c == ')';
}
bool parantezaDeschisa(char c)
{
    return c == '[' || c == '(';
}
bool _operator(char c)
{
    return strchr("+-/*", c);
}
bool operand(char c)
{
    return litera(c) || cifra(c);
}
bool litera(char c)
{
    return c >= 'a' && c <= 'z';
}
bool cifra(char c)
{
    return c >= '0' && c <= '9';
}
