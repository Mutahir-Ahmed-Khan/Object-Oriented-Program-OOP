#include <iostream>
using namespace std;

class Device{
	private:
	bool status; 
	strng device; 
	string type;
	
	protected: 
	double powerRating; 

	public:
		
	Device(string d, string t, double p) 
	 : device(d), type(t), powerRating(p) {}
	 
	 void turnOn(){
	 	status = true; 
	 }
	 void trunOff(){
	 	status = false;
	 }
	 
	 virtual double calculatePowerUsage(int hrs) {}
};

class Lights : public Device {
	public:
		Lights(string d, string t, double p) : Device(d,t,p) {}
		
		
	double calculatePowerUsage(int hrs) override {
		return hrs*powerRating;
	}
	
	void turnOn(){
	 	Device::turnOn();
	 	cout << "Ligh is OFF" << endl; 
	 }
	
	void trunOff(){
	 	Device::trunOff()
	 	cout << "Light is OFF" << endl;
	 }
	 
};

class Fans : public Device {
	private: 
		int speedFactor;
	public:
		Fans(string d, string t, double p. int f) : Device(d,t,p) , speedFactor(f) {}
		
		
	double calculatePowerUsage(int hrs) override {
		return hrs*powerRating*speedFactor;
	}
	
	void turnOn(){
	 	Device::turnOn();
	 	cout << "Fan is OFF" << endl; 
	 }
	
	void trunOff(){
	 	Device::trunOff()
	 	cout << "Fan is OFF" << endl;
	 }
};

class AC : public Device {
	private: 
		int currTemp; 
		int desTemp;
	public:
		AC(string d, string t, double p, int curr, int des) : Device(d,t,p) , currTemp(curr) desTemp(des) {}
		
		
	double calculatePowerUsage(int hrs) override {
		return (powerRating * hrs * (1 - currTemo - desTemp) / 100);
	}
};

class securitySystem : public Device{
	private:
		bool statusCheck;
		const double powerConsumption;
	public: 
		securitySystem(string d, string t, double p,bool check, double consumption) 
			: Device(d,t,p) , statusCheck(check) , powerConsumption(consumption) {}
			
	double calculatePowerUsage() override {
		return powerConsumption;
		
};



int main(){
     
}
