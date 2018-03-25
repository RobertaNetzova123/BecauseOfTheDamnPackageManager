#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <sstream>
#include <numeric>
#include <iomanip>
#include <string>

using namespace std;

class Exception {
	string error;
	public:

	Exception(string msg) : error(msg) {}
	string get_error() {
		return error;
	}
};

int main() {

	try {
		string input;
		vector<double> sample;
		cin >> input; //прочита един string от целия ред
	
		if(input == "END") {	
			throw Exception("ERR: PROVIDE AT LEAST ONE NUMBER");
		}

		string type_of_the_function;
		if(input == "strict" || input == "integers-only" || input == "strict:integers-only") {
			type_of_the_function = input; //запазваме го в нова променлива за да се проверявам по-късно
			cin >> input;
		}		

		while(input != "END") {
			istringstream brook(input); //от string-a input създава поток 
			double token;			
			brook >> token; //за да го набуташ в доубле променлива //за числата с повече от едно на ред

			//strict
			if(type_of_the_function == "strict") {
				if(!brook.fail()) { //ако няма букви а само числа в потока
					sample.push_back(token); //добавям числото най-накрая във вектора
				}
			 	else{
					throw Exception("ERR: PROVIDE ONLY NUMBERS");
				}
			}
				
			//integers-only
			else if(type_of_the_function == "integers-only") {
				if(!brook.fail()) {
					sample.push_back(floor(token)); //закръглява към по-малкото чсило
				}
			}

			//strict:integers-only
			else if(type_of_the_function == "strict:integers-only") {
				if(brook.fail()) { //ако имаме числа с десетична запетая
					throw Exception("ERR: PROVIDE ONLY NUMBERS");	
				}
				if(floor(token) == token) { //проверява дали е целочислено числото
					sample.push_back(token);
				} else {
					throw Exception ("ERR: PROVIDE ONLY INTEGERS");
				}

			}
			
			else{
				if(!brook.fail()) { //ако няма никакви подадени команди
					sample.push_back(token);
				}
			}
			
			cin >> input;	
		} 
			

		if(sample.empty()) {
			throw Exception ("ERR: PROVIDE AT LEAST ONE NUMBER"); //ако вектора е празен
		}
 
		double min = *min_element(sample.begin(), sample.end());
		cout << min << " ";
		double max = *max_element(sample.begin(), sample.end());
		cout << max << " ";
		double average = accumulate(sample.begin(), sample.end(), 0.0) / sample.size(); //accumulate събира всички числа и ги set-ва до един знак след десетичната запетая
		if(type_of_the_function == "integers-only" || type_of_the_function == "strict:integers-only") {
			cout << setprecision(2) << average << endl;
		}
		else cout << setprecision(4) << average << endl; //?????
	} catch(Exception ex) {
		cout << ex.get_error() << endl;
	}

	return 0;
}
