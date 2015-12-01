#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <strstream>
#include <cstdlib>

using namespace std;

bool MoveJPG (string &temp) {
    temp.replace(11,4,"");
} //end function

bool AddTwo (string &temp) {
    temp = "2" + temp;
} //end function

int main(int argc, char const *argv[])
{
    string line;
    ofstream ofs("IC_Number.txt");
    ifstream out("All_Stu_Number.txt");
    if (!out.is_open()) {
        cout << "Can't open this file" << endl;
        exit(0);
    }

    while(!out.eof()) {
        getline(out,line);
        
        MoveJPG(line);
        AddTwo(line);
        
        ofs << line << endl;
    }

    ofs.close();
    out.close();

    return 0;
}
