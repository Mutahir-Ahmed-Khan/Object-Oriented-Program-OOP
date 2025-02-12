#include <iostream>
using namespace std;

//"-----Forward declaration----------"//
class Skill;
class Student;
class Mentor;
class Sports;
//"-----------------------------------"//

class Student{
    public:
    int studentID;
    string studentName;
    int age;
    string* sportsInterests;
    string mentorAssigned;

    //Constructor 
    Student(int id, string name,int a) : studentID(id), studentName(name), age(a) {}

    //Mentor Registration
    void registerForMentorship(Mentor m);

    //Sports Interest Update
    void updateSportsInterest(Sports s);

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
    string* requiredSkill;

    //Constructor
    Sports(int id, string name, string desc) : sportID(id), sportName(name), description(desc) {}

    //add Skill
    void addSkill(Skill s);

    // //Remove Skills
    void removeSkill(Skill s);
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
//SKILL SECTION
void Skill :: showSkillDetail(){
    cout << "--------------------" << endl;
    cout << "Skill Name: " << skillName << endl;
    cout << "Description: "<< "'" << description << "'" << endl;
    cout << "--------------------" << endl;
}

void Skill :: updateSkillDescription(string newDescription){
    description = newDescription;
}

//SPORTS SECTION
//STUDENT SECTION 
//MENTOR SECTION 
//--------------------------------------------------------------//
int main(){

return 0;
}
