#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;
int main()
{
    ifstream file1;
    ofstream file2;
    fstream file;
    string exe = "prog.exe";
    string path = "test.cpp";
    string buf;
    uint32_t i = 0;
    file.open(path, ios::out);
    cout << endl << "\tWrite your code:" << endl << endl;
    if (file.is_open())
    {
        do
        {
            system("color 74");
            cout << "\t" << i << "  |  ";
            getline(cin, buf);
            if (buf[0] == '0')
            {
                break;
            }
            else
            {
                file << buf << endl;
                i++;
            }
        } while (true);
        cout << "Compile..." << endl;
        file.close();
    }
    else
    {
        cout << "Error! File isn't open!" << endl;
    }
    string command = "g++ -o " + exe + " " + path;
    system(command.c_str());
    command = "start " + exe;
    system(command.c_str());
    return 0;
}