#include <iostream>
using namespace std;

class Student{
    public:
    int studentID;
    string name;
    int age;
    string sportsInterests[5][100];
    string mentorAssigned;

    //Mentor Registration
    // void registerForMentorship(Mentor m);

    //Sports Interest Update
    // void updateSportsInterest(Sport s);

    //Mentor's Detail
    void viewMentorDetails();
};

class Mentor{
    public:
    int mentorID;
    string name;
    string sportExpertise[10][100];
    int maxLearners;
    string assignedLearners[10][100];

    //assign Learner 
    // void assignLearner(Student s);

    // //Remove Learner
    // void removeLearner(Student s);

    //Guidance 
    void provideGuidance();

    //View Learners 
    void viewLearners();
};

class Sports{
    public:
    int sportID;
    string name; 
    string description;
    string requiredSkil[100];

    //add Skill
    // void addSkill(Skill s);

    // //Remove Skills
    // void removeSkill(Skill s);
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

//Defining Functions
//SKILL Section 
void Skill :: showSkillDetail(){\
    cout << "--------------------" << endl;
    cout << "Skill Name: " << skillName << endl;
    cout << " ( " << description << " ) " << endl;
    cout << "--------------------" << endl;
}

void Skill :: updateSkillDescription(string newDescription){
    description = newDescription;
}

//Sport Section 

int main(){
    Skill skill01(1030,"Football","Played Since 12");


    skill01.updateSkillDescription("Played since 18");
    skill01.showSkillDetail();


return 0;
}
