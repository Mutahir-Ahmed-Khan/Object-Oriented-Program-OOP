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
    void registerForMentorship(Mentor m);

    //Sports Interest Update
    void updateSportsInterest(Sport s);

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
    void assignLearner(Student s);

    //Remove Learner
    void removeLearner(Student s);

    //Guidance 
    void provideGuidance();

    //View Learners 
    void viewLearners();
};

class Sports{
    int sportID;
    string name; 
    string description;
    string requiredSkil[100];

    //add Skill
    void addSkill(Skill s);

    //Remove Skills
    void removeSkill(Skill s);
};

class Skill{
    int skillID;
    string skillName;
    string description;

    //Skill Detail
    void skillDetail();

    //Add New Desccription
    updateSkillDescription(string newDescription);
};

int main(){

return 0;
}
