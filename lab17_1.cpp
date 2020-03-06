#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(){

    vector <string> name_list;
    vector <string> score_list;
    string input;

    string format;

    ifstream text("name_score.txt");

    while(getline(text,input)){

        sscanf(input,"%s:%s %d",name_list[0]);
        cout << name_list;
    }

    // string command;

    // cout<<"Please input your command : ";
    // getline(cin,command);

    // if(command)

    // if(command)

    // if(command == "exit")   break;
}
