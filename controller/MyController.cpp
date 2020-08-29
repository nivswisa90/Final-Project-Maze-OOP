//
// Created by Niv Swisa on 23/08/2020.
//
#include "../controller/MyController.h"


MyController::MyController(view *view)
{
    _view = view;
    _model  = new MyModel;
    _model->addObserver(*this); // add controller as our only observer

    // initialize all the commands with the view and to model to connect them with the controller
    _commands["dir"] = new Dir(_model,_view);
    _commands["generate maze"] = new GenerateMazeCommand(_model,_view);
    _commands["display"] = new Display(_model,_view);
    _commands["save maze"] = new SaveMaze(_model,_view);
    _commands["load maze"] = new LoadMaze(_model,_view);
    _commands["maze size"] = new MazeSize(_model,_view);
    _commands["file size"] = new FileSize(_model,_view);
    _commands["solve"] = new SolveMaze(_model,_view);
    _commands["display solution"] = new DisplaySolution(_model,_view);
    _commands["exit"] = new Exit(_model,_view);
}

Command* MyController::get(const string& command)
{
    auto it = _commands.find(command);
    if (it == _commands.end())
        return nullptr;

    return it->second;
}

void MyController::Update(Observable& o)
{
    //1 for completed action
    this->setStatus(1);
    // display to the user the stream from the model and controller
}
