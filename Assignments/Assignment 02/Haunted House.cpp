#include <iostream>
using namespace std;

//-------------------------------------------------------------Ghosts------------------------------------------------------------
class Ghosts{
    private:
    string workerName;
    int scareLevel;

    public:
    //Constructor
    Ghosts(string name,int level) : workerName(name), scareLevel(level) {}

    //Functions
    virtual void haunt() = 0;
};

class poltergeists : public Ghosts{
    public:
    //Constructor
    poltergeists(string name) : Ghosts(name,4) {}

    //Function 
    void haunt() override{
        cout << "*Moving Table" << endl;
        cout << "*Moving Chair" << endl;
    }
};

class Banshees : public Ghosts{
    public:
    //Constructor 
    Banshees(string name) : Ghosts(name,2) {}

    //Function 
    void haunt() override{
        cout << "*Screaming Loudly" << endl;
    }
};

class ShadowGhosts : public Ghosts{
    public:
    //Constructor 
    ShadowGhosts(string name) : Ghosts(name,8);

    //Function 
    void haunt() override {
        cout << "*Whispering Crrepily" << endl;
    }
};
//-----------------------------------------------------------------------------------------------------


class hauntedHouse{
    private:
    string name;
    Ghosts *ghosts;

    public:
    //Constructor
    //Functions

  
};

class Visitor{
    private:
    string name;
    int bravery;

    public:
    //Constructor 
    //Functions

};


int main(){

    return 0;
}
