#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

int systemCompile(string name);

int main() {
    std::cout << "Hello, World!" << std::endl;

system("gcc -o wasd test.cpp");
    system("ls >> interim.txt");

    char buffer[4];

    string temp = "a";
    ifstream ifs;
    ifs.open("interim.txt");
    //NOTE: while loop tries to identify files ending in .cpp
    while(!ifs.eof()) {
        ifs >> temp;
        cout << temp << endl;
        cout << temp.length() << endl;
        temp.copy(buffer,4,temp.length()-4);
        cout << buffer << endl;
        if(!strcmp(buffer,".cpp")){
            cout << "cpp identified, runnung system compile" << endl;
            systemCompile(temp);
        }
    }
    ifs.close();



    return 0;
}

int systemCompile(string name){
    string call;
    call = "gcc -o " + name.substr(0,name.length()-4) +" "+ name;
    cout << call << endl;
    system(call.c_str());
    return 0;
}