#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(){

    vector <string> name_list;
    vector <int> score_list;
    vector <string> grade_list;
    vector <string> low_name_list;
    string input;

    char name[100];
    int num1, num2, num3;

    ifstream text("C:\\Users\\acer\\Documents\\GitHub\\lab17-2562-2-arclxngth\\name_score.txt");

    while(getline(text,input)){

        int sum=0;

        sscanf(input.c_str(),"%[^:]:%d %d %d",name,&num1,&num2,&num3);

        sum = num1+num2+num3;

        name_list.push_back(name);
        score_list.push_back(sum);

    }

    for(int i=0; i<score_list.size(); i++){

        if(score_list[i]>=80)         grade_list.push_back("a");
        else if(score_list[i]>=70)    grade_list.push_back("b");
        else if(score_list[i]>=60)    grade_list.push_back("c");
        else if(score_list[i]>=50)    grade_list.push_back("d");
        else                          grade_list.push_back("f");
    }

    while(true){

        string command;
        int i=0;

        cout<<"Please input your command : ";
        getline(cin,command);
        
        while(command[i]){

            command[i] = tolower(command[i]);
            i++;
        }


        for(int list = 0; list < name_list.size(); list++){
 
            int j = 0;
            string low_name = "";

            while(name_list[list][j]){

                low_name += tolower(name_list[list][j]);
                j++;
            }
            low_name_list.push_back(low_name);
        }

        int space_pos = command.find_first_of(" ");
        string command_main = command.substr(0,space_pos);

        string target = command.substr(space_pos+1,command.size());

        int count = 0;

        if(string(command_main) == "name"){

            for(int i=0; i<name_list.size(); i++){

                if(low_name_list[i] == target)  {

                    cout<<name_list[i]<<"'s grade = "<<grade_list[i]<<endl;
                    count++;
                }
            }
            if(count = 0) cout<<"Cannot found"<<endl;
        }

        else if(string(command_main) == "grade"){

            for(int i=0; i<grade_list.size(); i++){

                if(grade_list[i] == target)  {
                    
                    cout<<name_list[i]<<endl;
                    count++;
            }
        }

            if(count=0) cout<<"Cannot found"<<endl;
        }

        else if (string(command_main) == "exit")    break;

        else    cout<<"Invalid command"<<endl;
        cout<<"--------------------------------"<<endl;
    }
}
