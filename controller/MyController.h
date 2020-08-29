//
// Created by Niv Swisa on 23/08/2020.
//

#ifndef FINAL_PROJECT_MYCONTROLLER_H
#define FINAL_PROJECT_MYCONTROLLER_H


#include "../controller/Controller.h"
#include "../model/Observer.h"
//#include "Command.h"
#include "GenerateMazeCommand.h"
#include "../model/MyModel.h"
#include "../view/view.h"
#include "../controller/Display.h"
#include "../controller/DisplaySolution.h"
#include "../controller/SolveMaze.h"
#include "../controller/SaveMaze.h"
#include "../controller/LoadMaze.h"
#include "../controller/FileSize.h"
#include "../controller/MazeSize.h"
#include "../controller/Dir.h"
#include "../controller/Exit.h"

class MyController :public Controller,public Observer {
private:
    map<string, Command*> _commands;
    bool _observerStatus;
    MyModel* _model;
    view* _view;

public:
    MyController(view *view);
    ~MyController()
    {
//        for (auto it = _commands.begin(); it != _commands.end(); ++it)
//        {
//            delete it->second;
//        }
//
//        delete _model;
    }
    virtual Command* get(const string& command);
    virtual void Update(Observable& o);

    bool getStatus() { return _observerStatus; }
    void setStatus(bool status){_observerStatus = status;}

};




#endif //FINAL_PROJECT_MYCONTROLLER_H
