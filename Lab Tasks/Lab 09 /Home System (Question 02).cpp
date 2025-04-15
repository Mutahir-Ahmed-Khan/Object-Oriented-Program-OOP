#include <iostream>
using namespace std;

class SmartDevice{
	
	public:
		SmartDevice(){
			
		}
		
		virtual void turnOn() =0;
		virtual void turnOff() =0;
		virtual bool getStatus()=0;
		
};


class LightBlub:public SmartDevice{
	
	private:
		bool isOn;
		int brightness;
		
	public:
		LightBlub(bool check,int br):SmartDevice(){
			isOn = check;
			brightness=  br;
			
		}
		
		void turnOn(){
			cout <<"Turning the Blub ON"<<endl;
			isOn = true;
		}
		void turnOff(){
			cout <<"Turning the Blub OFF"<<endl;
			isOn = false;
		}
		
		bool getStatus(){
			cout <<"Getting Status of Blub"<<endl;
			return isOn;
		}
};




class Thermostat:public SmartDevice{
	
	private:
		bool isOn;
		double temperature;
		
	public:
		Thermostat(bool check,double temp):SmartDevice(){
			isOn = check;
			temperature   = temp;
			
		}
		
		void turnOn(){
			cout <<"Turning the thermostat ON"<<endl;
			isOn = true;
		}
		void turnOff(){
			cout <<"Turning the thermostat OFF"<<endl;
			isOn = false;
		}
		
		bool getStatus(){
			cout <<"Getting Temp status of thermostat"<<endl;
			if (temperature>0){
				return true;
			}
			else{
				return false;
			}
		}
};


int main(){
	
	LightBlub  bulb1(false,50);
	Thermostat  thermo1(false,25.7);
	
	cout <<bulb1.getStatus()<<endl;
	bulb1.turnOn();
	cout <<bulb1.getStatus()<<endl;
	
	
	cout <<thermo1.getStatus()<<endl;
	thermo1.turnOn();
	cout <<thermo1.getStatus()<<endl;
	
}
