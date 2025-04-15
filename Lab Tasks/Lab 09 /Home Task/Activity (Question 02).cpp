#include <iostream>
using namespace std;

class Activity{
    public:
    Activity() {}
    virtual void calculateCaloriesBurned() = 0;
};

class Running:public Activity{
    private:
    double distance;
    double time;

    public:
    Running(double dis, double t) : distance(dis), time(t), Activity() {}
    void calculateCaloriesBurned() override{
        cout << "Calculating for Running" << endl;
    }
};

class Cycling: public Activity{
    private:
        double speed; 
        double time; 
    public:
        Cycling(double s,double t) : speed(s), time(t), Activity() {}
        void calculateCaloriesBurned() override{
            cout << "Calculating for Cycling" << endl;
        }
     

};

int main(){
Activity *ptr; 
Cycling c(100,2);
Running r(1000,10);

ptr = &c;
ptr->calculateCaloriesBurned();

ptr = &r;
ptr->calculateCaloriesBurned();

    return 0;
}
