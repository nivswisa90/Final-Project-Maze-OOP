//
// Created by Niv Swisa on 23/08/2020.
//

#include "CLI.h"
#include "sstream"
void CLI::start()
{

    string command="";
    Command* com;
    MyController* controller = new MyController(this);
    while (command != "exit") {
        cout << ">>" << endl;
        getline(cin, command);
        vector<string> para = convertToParameters(command);
        string str=para[0];
        if(para.size()>2){
            if(str!="solve" ){
                str+=" "+para[1];
            }
        }
        com = controller->get(str);

        if (nullptr != com) {
            com->execute(para);
        }
        else {
            cout << "Unsoported command!" << endl;
        }
    }
}
ostream &CLI::getOut()
{
    return _out;
}

vector<string> CLI::convertToParameters(string s) {
    vector<string> token;
    stringstream check(s);
    string tmp;
    while(getline(check,tmp,' '))
    {
        token.push_back(tmp);
    }
    return token;
}
