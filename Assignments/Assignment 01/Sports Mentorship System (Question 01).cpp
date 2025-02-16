#include <iostream>
using namespace std;

//-------Forward declaration----------//
class Skill;
class Mentor;
class Sports;
//-----------------------------------//

class Student{
    public:
    int studentID;
    string studentName;
    int age;
    string* sportsInterests;
    Mentor* mentorAssigned;

    //Constructor 
    Student(int id, string name,int a) : studentID(id), studentName(name), age(a) {
        sportsInterests = new string[5];
    }
    //Destructor 
    ~Student(){
        delete[] sportsInterests;
    }

    //Mentor Registration
    void registerForMentorship(Mentor* m);

    //Sports Interest Update
    void updateSportsInterest(Sports* s);

    //Mentor's Detail
    void viewMentorDetails();
};

class Mentor{
    public:
    int mentorID;
    string name;
    string* sportExpertise;
    int maxLearners;
    string* assignedLearners;

    //assign Learner 
    void assignLearner(Student s);

    // //Remove Learner
    void removeLearner(Student s);

    //Guidance 
    void provideGuidance();

    //View Learners 
    void viewLearners();
};

class Sports{
    public:
    int sportID;
    string sportName; 
    string description;
    Skill** requiredSkill;
    int skillCount = 0;

    //Constructor
    Sports(int id, string name, string desc) : sportID(id), sportName(name), description(desc) {
        requiredSkill = new Skill*[5];
    }
    //Destructor 
    ~Sports(){
        delete[] requiredSkill;
    }

    //add Skill
    void addSkill(Skill* s);

    // //Remove Skills
    void removeSkill(Skill* s);
};

class Skill{
    public:
    int skillID;
    string skillName;
    string description;

    //Constructor for Skill Section 
    Skill(int id, string name, string desc) : skillID(id), skillName(name), description(desc) {}

    //Skill Detail
    void showSkillDetail();

    //Add New Desccription
    void updateSkillDescription(string newDescription);
};

//--------------------Defining Functions------------------------//
//SKILL SECTION (DONE) ---------------------------------------//
void Skill :: showSkillDetail(){
    cout << "--------------------" << endl;
    cout << "Skill Name: " << skillName << endl;
    cout << "Description: "<< "'" << description << "'" << endl;
    cout << "--------------------" << endl;
}

void Skill :: updateSkillDescription(string newDescription){
    description = newDescription;
}
//-------------------------------------------------------------//

//SPORTS SECTION------------------------------------------------
void Sports :: addSkill(Skill* s){
    if (skillCount < 5){
        requiredSkill[skillCount++] = s;
        cout << "Skill " << s->skillName<< " Added Successfully " << "To " << sportName <<  endl;
    }
    else{
        cout << "Maximum Skill have been added" << endl;
    }
}

void Sports :: removeSkill(Skill* s){
    for (int i = 0; i < skillCount; ++i) {
        if (requiredSkill[i] == s) {
            for (int j = i; j < skillCount - 1; ++j) {
                requiredSkill[j] = requiredSkill[j + 1]; 
            }
            skillCount--;
            cout << "Skill " << s->skillName << " removed from " << sportName << endl;
            return;
        }
    }
    cout << "Skill " << s->skillName << " not found in " << sportName << endl;
}
//---------------------------------------------------------------------

//STUDENT SECTION------------------------------------------------------//
void Student :: registerForMentorship(Mentor* m){
    mentorAssigned = m;
}

void Student :: updateSportsInterest(Sports* s){
    static int SportInterestCount = 0;
    if(SportInterestCount < 5){
        cout << "Enter the Sports you wanted to add: ";
        cin >> sportsInterests[SportInterestCount];
        SportInterestCount++;
    }
    else{
        cout << "Already Maximum Sport Interest" << endl;
    }
}

void Student :: viewMentorDetails(){
    if(mentorAssigned){
        cout << "Mentor Name: " << mentorAssigned->name << endl;
        cout << "Mentor ID: " << mentorAssigned->mentorID << endl;
    }
    else{
        cout << "No Mentor Assigned" << endl;
    }
}
//MENTOR SECTION -----------------------------------------------------//
//--------------------------------------------------------------//
int main(){

return 0;
}
