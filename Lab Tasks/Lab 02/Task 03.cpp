Write a C++ program that:
 Dynamically allocates a 2D array using pointers (not using vector or standard containers).
 Fills the array with random integers between 1 and 100.
 Pass the 2D array to function to perform these tasks:
 Calculates and prints The sum of all elements in the array.
 Calculates and prints The sum of each row and each column.
 Calculates and prints The row and column with the highest sum.
 Pass the 2D array to a function to transpose the matrix and print the resulting matrix.
Free the dynamically allocated memory.
Note:
Use functions to perform the calculations and matrix operations (do not write all code inside main()).
Handle edge cases, such as when the array has no elements or is improperly allocated.

#include <iostream> 
using namespace std;

void performTask(int** arr){
	int Rsum = 0;
	int sum = 0;
	int Rgreatest = -999;
	int Rhigh;

	int Csum = 0;
	int Cgreatest = -999;
	int Chigh;
	//Sum Of All Elements 
	for(int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			sum = sum + arr[i][j];
		}
	}
	cout << "The sum is " << sum << endl;
	sum = 0;
	
	//Sum of Rows
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			sum = sum + arr[i][j];
		}
		cout << "The Sum of Row " << i + 1 << "th is " << sum << endl;
		sum = 0;
	}
	
	//The Row with Highest sum 
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			Rsum = Rsum + arr[i][j];
		}
		if(Rsum > Rgreatest){
			Rgreatest = Rsum;
			Rhigh = i;
		}
	}
	cout << "The Row with the Highest sum is: Row " << Rhigh <<endl;

	//The Column with Highest Sum 
	for(int i = 0; i < 3; i++){
		Csum = 0;
		for(int j = 0; j < 3; j++){
			Csum = Csum + arr[j][i];
		}
			if(Csum > Cgreatest){
				Cgreatest = Csum;
				Chigh = i;
			}
	}
	cout << "The Column with the Highest sum is: Column " << Chigh + 1 <<endl;

}

void transposed(int** arr){
	int newarr[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			newarr[i][j] = arr[j][i];
		}
	}

	cout << "The Transposed Matrix is: " << endl;
	for(int i = 0; i < 3; i++){
		cout << "[";
		for(int j = 0; j < 3; j++){
			cout << newarr[i][j] << ",";
		}
		cout << "]" << endl;
	}
}

int main(){
	int** arr = new int*[3];
	for (int i = 0; i < 3; i++){
		arr[i] = new int[3];
	}
	
	//Filing it wit random Numbers between 1 to 100
	int values[3][3] = {
        {12, 35, 56},
        {8, 45, 67},
        {23, 54, 34}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = values[i][j];
        }
    }
	
	performTask(arr);
	transposed(arr);

	for(int i = 0; i < 3; i++){
		delete[] arr[i];
	}

	delete[] arr;

}
