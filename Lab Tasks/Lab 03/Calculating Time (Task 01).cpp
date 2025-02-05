
#include <iostream>
using namespace std;

class time{
    public:
        int hours;
        int minutes;
        int seconds;

        //constructor to initailize all values to zero 
        time():hours(0), minutes(0), seconds(0){
        }
        
        //constructor to iniizlie to fix values
        time(int H, int M, int S):hours(H), minutes(M), seconds(S) {}

        // Display Function
        void display()const{
            cout << hours << ":" << minutes << ":" << seconds << endl;
        }
        // adding two objects of type time
        time add(const time &obj) const {
            time result;
            result.seconds = seconds + obj.seconds;
            result.minutes = minutes + obj.minutes;
            result.hours = hours + obj.hours;

            if (result.seconds >= 60){
                result.seconds = result.seconds - 60;
                result.minutes++;
            }

            if(result.minutes >= 60){
                result.minutes = result.minutes - 60;
                result.hours++;
            }

            if(result.hours >= 24){
                result.hours = result.hours - 24;
            }

            return result;
        }

};

int main(){
    const time obj1(10,30,45);
    const time obj2(5,45,20);

    time obj3;

    obj3 = obj1.add(obj2);

    cout << "Time 01: ";
    obj1.display();

    cout << "Time 02: ";
    obj2.display();

    cout << "The Sum of both time is:";
    obj3.display();

    return 0;
}
