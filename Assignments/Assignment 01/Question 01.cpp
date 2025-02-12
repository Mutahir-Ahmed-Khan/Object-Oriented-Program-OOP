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
    void registerForMentorship(string mentorAssigned);

    //Sports Interest Update
    void updateSportsInterest();

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
    void assignLearner();

    //Remove Learner
    void removeLearner();

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
    void addSkill();

    //Remove Skills
    void removeSkill();
};

class Skill{
    int skillID;
    string skillName;
    string description;

    //Skill Detail
    
};

int main(){

return 0;
}
