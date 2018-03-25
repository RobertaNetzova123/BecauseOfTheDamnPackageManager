#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <sstream>
#include <numeric>
using namespace std;

//class Error {};

void print_vector(vector<int>& vctr) {
	for(vector<int>::iterator it = vctr.begin(); it != vctr.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

int main() {
	string input;
	vector<double> calc;
	
	bool only_strict = false;
	double token;
	string butt;
	
	//chete red ot potoka
	//getline(cin, input);
	do {
		getline(cin, input);
		istringstream my_stream(input);
		
	
		while(!my_stream.eof() && input != "END") 
		{
			my_stream >> butt;
			
			
			if(butt == "strict") 
			{
				//cout << "hello";
				
				//my_stream >> token;
				if(!my_stream.fail()) 	
				{
					//my_stream >> token;
					calc.push_back(token);
					
				}
				else 
				                                                                                                                           {
					if(only_strict == true) 
					{
						break;
					} else {
			
						my_stream.clear();
						my_stream.ignore(); 
					}
					
				}
 			}
			//getline(cin, input);
			
		}
		
		/*else if (input == "integers-only") {

		}
		
		else if(input == "strict:integers-only") {

		}*/
	}	while(input != "END");
	
		double max = *max_element(calc.begin(), calc.end());
		double min = *min_element(calc.begin(), calc.end());
		double average = accumulate(calc.begin(), calc.end(), 0.0) / calc.size();
		cout << min << " " << max << " " << average;
	
	return 0;
}

