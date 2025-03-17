#include <iostream>
#include <iomanip>
using namespace std;

//-------------------------------------------------------------Ghosts------------------------------------------------------------//
class Ghosts{
    private:
    string workerName;
    int scareLevel;

    public:
    //Constructor
    Ghosts(string name,int level) : workerName(name), scareLevel(level) {}

    //Functions
    virtual void haunt() = 0;

    int getLevel(){
        return scareLevel;
    }
};


//Virtual Function because both Child Ghost inherit from Ghosts Parent (Copy of the Ghost is Avoided)
class poltergeists : virtual public Ghosts{
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

class ShadowGhosts :  virtual public Ghosts{
    public:
    //Constructor 
    ShadowGhosts(string name) : Ghosts(name,8) {}

    //Function 
    void haunt() override {
        cout << "*Whispering Creepily" << endl;
    }
};

//Question have only discussed about ShadowPoltergeists
class Mutants : public ShadowGhosts, public poltergeists{
    public:
    //Constructor 
    Mutants(string name) : ShadowGhosts(name), poltergeists(name) , Ghosts(name, 10){}

    //Functions
    void haunt() override {
        ShadowGhosts::haunt();
        poltergeists::haunt();
    }
};

//--------------------------------------------------------------------------------------------------------------------------------------//

//------------------------------------------Haunted House -----------------------------------------------------------------------------//
class hauntedHouse{
    private:
    string name;
    Ghosts *ghosts;

    public:
    //Constructor
    hauntedHouse(string n, Ghosts *g) : name(n), ghosts(g) {}

    //Functions
    void Haunted(){
        cout << "--------- NAME ---------" << endl;
        cout << right << setw(18) << name << endl;
        cout << "------------------------" << endl;
       

        ghosts->haunt();
    }
  
};

//--------------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------Visitor------------------------------------------------------------------------//
class Visitor {
    private:
    string name;
    int bravery;
    Ghosts *ghost;

    public:
    //Constructor (No need to call Ghost Constructor)
    Visitor(string n, int b,Ghosts *g) : name(n), bravery(b), ghost(g) {}

    //Functions
    void Reaction(){
        if(bravery < ghost->getLevel()){
            cout << name << "Running Away " << endl;
        }
        else{
            cout << name << "Laughing " << endl;
        }
    }

};
//----------------------------------------------------------------------------------------------------------------------------------------//


int main(){
    poltergeists poltergeist("Casper");
    Banshees banshee("Screamer");
    ShadowGhosts shadowGhost("Dark Whisper");
    Mutants mutantGhost("Hybrid Phantom");

    hauntedHouse house1("Spooky Manor", &poltergeist);
    hauntedHouse house2("Phantom Castle", &banshee);
    hauntedHouse house3("Ghostly Shack", &shadowGhost);
    hauntedHouse house4("Mutant Lair", &mutantGhost);

    Visitor visitor1("John", 5, &banshee);
    Visitor visitor2("Alice", 9, &mutantGhost);

    house1.Haunted();
    visitor1.Reaction(); 

    house2.Haunted();
    visitor1.Reaction();  

    house3.Haunted();
    visitor2.Reaction();  

    house4.Haunted();
    visitor2.Reaction(); 

    return 0;
}
