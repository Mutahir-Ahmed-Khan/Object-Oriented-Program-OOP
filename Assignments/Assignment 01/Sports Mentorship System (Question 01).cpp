#include <iostream>
using namespace std;

//mentor Assigned's data-type would be mentor and wil store whole object of mentor (miss abeeha)

//"-----Forward declaration----------"//
class Skill;
class Mentor;
class Sports;
//"-----------------------------------"//

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
    Student** assignedLearners;
    int currentLearners;

    //Constructor
    Mentor(int id, string n) : mentorID(id), name(n), maxLearners(3),currentLearners(0){
        sportExpertise = new string[3];
        assignedLearners = new Student*[3];
    }
    //Destructor 
    ~Mentor() {
        delete[] sportExpertise;
        delete[] assignedLearners;  
    }
    

    //assign Learner 
    void assignLearner(Student* s);

    // //Remove Learner
    void removeLearner(Student* s);

    //Guidance 
    void provideGuidance();

    //View Learners 
    void viewLearner();
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

void Student::updateSportsInterest(Sports* s){
    int SportInterestCount = 0; 
    if(SportInterestCount < 5){
        sportsInterests[SportInterestCount] = s->sportName;
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
void Mentor :: assignLearner(Student* s){
    if(currentLearners < maxLearners){
        assignedLearners[currentLearners++] = s;
        cout << "Student " << s->studentName  << " Assigned to "<< name<< endl;
    }
    else{
        cout << "Max Learners Have Reached" << endl;
    }
}

void Mentor :: removeLearner(Student* s){
    for (int i = 0; i < currentLearners; ++i) {
        if (assignedLearners[i] == s) {
            for (int j = i; j < currentLearners - 1; ++j) {
                assignedLearners[j] = assignedLearners[j + 1]; 
            }
            currentLearners--;
            cout << s->studentName << " has been removed from " << name << "'s mentorship" << endl;
            return;
        }
    }
    cout << s->studentName << " is not assigned to " << name << endl;
}

void Mentor::viewLearner(){
    cout << "---------- Learners ----------" << endl;
    for(int i = 0; i < currentLearners ; i++){
        cout << i + 1 << "- " << assignedLearners[i]->studentName << endl;
    }
    cout << "------------------------------" << endl;
}


void Mentor::provideGuidance(){
    cout << "Students should set clear goals, develop strong study habits, and stay curious about learning beyond textbooks." << endl;
    cout << "Effective time management, avoiding procrastination, and prioritizing tasks are essential for success." << endl;
    cout << "Communication skills, both written and spoken, help in academic and professional growth." << endl;
    cout << "Staying disciplined, seeking mentorship, and balancing studies with self-care ensure overall development." << endl;
    cout << "Most importantly, embrace challenges as learning opportunities and keep striving for improvement." << endl;
}


//--------------------------------------------------------------//
int main(){
    // Create Skills
    Skill* skill1 = new Skill(101, "Agility", "Improves speed and movement");
    Skill* skill2 = new Skill(102, "Strength", "Enhances muscle power");
    
    // Create Sports
    Sports* football = new Sports(1, "Football", "A team sport played with a ball");
    Sports* basketball = new Sports(2, "Basketball", "A sport involving dribbling and shooting");

    // Add skills to sports
    football->addSkill(skill1);
    basketball->addSkill(skill2);

    // Create Mentors
    Mentor* mentor1 = new Mentor(201, "Miss Abeeha");
    Mentor* mentor2 = new Mentor(202, "Mr. John");

    // Create Students
    Student* student1 = new Student(301, "Ali", 18);
    Student* student2 = new Student(302, "Sara", 19);

    // Assign sports interests to students
    student1->updateSportsInterest(football);
    student2->updateSportsInterest(basketball);

    // Assign mentor to students
    student1->registerForMentorship(mentor1);
    student2->registerForMentorship(mentor2);

    // Assign students to mentors
    mentor1->assignLearner(student1);
    mentor2->assignLearner(student2);

    // Display Mentor Details
    student1->viewMentorDetails();
    student2->viewMentorDetails();

    // View Learners under a mentor
    mentor1->viewLearner();
    mentor2->viewLearner();

    // Mentor providing guidance
    mentor1->provideGuidance();

    delete skill1;
    delete skill2;
    delete football;
    delete basketball;
    delete mentor1;
    delete mentor2;
    delete student1;
    delete student2;

    return 0;
}
