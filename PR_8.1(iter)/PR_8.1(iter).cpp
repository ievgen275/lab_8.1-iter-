#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str)
{
	for (int i = 0; str[i + 1] != 0; i++)
		if ((str[i] == 's' && str[i + 1] == 'q') || 
			(str[i] == 'q' && str[i + 1] == 's'))
			return 1;
	return 0;
}

char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 3)
        return str;

    char* tmp = new char[len * 4 / 3 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;

    while (i < len && str[i + 1] != 0) {
        if ((str[i] == 's' && str[i + 1] == 'q') ||
            (str[i] == 'q' && str[i + 1] == 's')) {
            *t++ = '*';
            *t++ = '*';
            *t++ = '*';
            i += 2;
        }
        else {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';

    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 'SQ or QS'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;

    return 0;
}