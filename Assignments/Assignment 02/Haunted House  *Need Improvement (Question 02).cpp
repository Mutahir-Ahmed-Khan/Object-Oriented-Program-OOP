#include <iostream>
#include <iomanip>
using namespace std;

class Ghosts {
private:
    string workerName;
    int scareLevel;

public:
    Ghosts(string name, int level) : workerName(name), scareLevel(level) {}

    virtual void haunt() = 0;

    int getLevel() {
        return scareLevel;
    }

    string getName() {
        return workerName;
    }

    virtual ~Ghosts() {} 

    friend class Mutants;
    friend Ghosts* operator+(Ghosts &g1, Ghosts &g2);
};

class poltergeists : virtual public Ghosts {
public:
    poltergeists(string name) : Ghosts(name, 4) {}

    void haunt() override {
        cout << "*Moving Table" << endl;
        cout << "*Moving Chair" << endl;
    }
};

class Banshees : public Ghosts {
public:
    Banshees(string name) : Ghosts(name, 2) {}

    void haunt() override {
        cout << "*Screaming Loudly" << endl;
    }
};

class ShadowGhosts : virtual public Ghosts {
public:
    ShadowGhosts(string name) : Ghosts(name, 8) {}

    void haunt() override {
        cout << "*Whispering Creepily" << endl;
    }
};

class Mutants : public ShadowGhosts, public poltergeists {
public:
    Mutants(string name, int level = 10) 
        : ShadowGhosts(name), poltergeists(name), Ghosts(name, level) {}

    void haunt() override {
        ShadowGhosts::haunt();
        poltergeists::haunt();
    }
};

Ghosts* operator+(Ghosts &g1, Ghosts &g2) {
    string newName = g1.getName() + " & " + g2.getName();
    int newLevel = g1.getLevel() + g2.getLevel();
    return new Mutants(newName, newLevel);
}

class hauntedHouse {
private:
    string name;
    Ghosts *ghost;

public:
    hauntedHouse(string n, Ghosts *g) : name(n), ghost(g) {}

    void Haunted() {
        cout << "--------- NAME ---------" << endl;
        cout << right << setw(18) << name << endl;
        cout << "------------------------" << endl;
        ghost->haunt();
    }
};

class Visitor {
private:
    string name;
    int bravery;
    Ghosts *ghost;

public:
    Visitor(string n, int b, Ghosts *g) : name(n), bravery(b), ghost(g) {}

    void Reaction() {
        if (bravery < ghost->getLevel()) {
            cout << name << " is Running Away!" << endl;
        } else {
            cout << name << " is Laughing!" << endl;
        }
    }
};

int main() {
    poltergeists poltergeist("Casper");
    Banshees banshee("Screamer");
    ShadowGhosts shadowGhost("Dark Whisper");
    Mutants mutantGhost("Hybrid Phantom");

    Ghosts *combinedGhost = poltergeist + shadowGhost;

    hauntedHouse house1("Spooky Manor", &poltergeist);
    hauntedHouse house2("Phantom Castle", &banshee);
    hauntedHouse house3("Ghostly Shack", &shadowGhost);
    hauntedHouse house4("Mutant Lair", &mutantGhost);
    hauntedHouse house5("Hybrid Haunt", combinedGhost);

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

    house5.Haunted();
    visitor2.Reaction(); 

    delete combinedGhost;

    return 0;
}
