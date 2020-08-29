//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_CLI_H
#define FINAL_PROJECT_CLI_H

#include "view.h"
#include "../controller/MyController.h"
using namespace std;
class CLI :public view {
private:
    std::ostream& _out;
    std::istream& _in;
public:
    CLI(ostream& out, istream& in) :_out(out), _in(in) {}
    virtual void start();
     virtual ostream & getOut();// function to print from the view and not from the controller
     vector<string> convertToParameters(string s);//function to understand user string
};


#endif //FINAL_PROJECT_CLI_H
