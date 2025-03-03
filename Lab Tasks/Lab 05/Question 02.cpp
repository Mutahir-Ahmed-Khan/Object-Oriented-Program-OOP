#include <iostream>
using namespace std;

class validateString{
	public:
	string Input;
	
	//Constructor 
	validateString(string i) : Input(i) {}
	
	//Function
	void check() const{
		bool
		for(int i = 0; i < Input.size(); i++){
			if(Input[i] > 'A' && Input[i]< 'Z' || Input[i] > 'a' && Input[i] < 'z'){
					
				}
			
			}
		}
};

int main(){
	validateString s1("sameed");
	s1.check();
}
