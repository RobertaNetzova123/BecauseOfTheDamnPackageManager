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
void print_vector(vector<int>& vctr) {
	for(vector<int>::iterator it = vctr.begin(); it != vctr.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

class Exception {
	string error;
	public:

	Exception(string msg) : error(msg) {}
	string get_error() {
		return error;
	}
};

int main() 
{
	try {
	string input;
	vector<double> sample;
	cin >> input;
	
	if(input == "END") {	
		throw Exception("ERR: PROVIDE AT LEAST ONE NUMBER");
	}

	string type_of_the_function;
	if(input == "strict" || input == "integers-only" || input == "strict:integers-only")
	{
		type_of_the_function = input; 
		cin >> input;
		
	}
	
	
	while(input != "END")
	{
		istringstream nemo(input);
		double token;
		//nemo	
			nemo >> token;
			
				
				
			
	
		if(type_of_the_function == "strict") 
		{
			if(!nemo.fail()) {
				sample.push_back(token);
				
			}
			else {
				throw Exception("ERR: PROVIDE ONLY NUMBERS");
				
		}
		
		}
			else if(type_of_the_function == "integers-only")
			{
				if(!nemo.fail())
				{
					sample.push_back(floor(token));
				}
			}

			else if(type_of_the_function == "strict:integers-only")
			{
				
				if(nemo.fail())
				{
					throw Exception("ERR: PROVIDE ONLY NUMBERS");	
				}
				if(floor(token) == token)
				{	
					sample.push_back(token);
					
					
					
				} else
				{
					throw Exception ("ERR: PROVIDE ONLY INTEGERS");
					
				}

			} 
			
			else{
				if(!nemo.fail()) {
					sample.push_back(token);
			}
				}

		
		
		cin >> input; //rip nemo
			
	}
	
	if(sample.empty())
		{
			throw Exception ("ERR: PROVIDE AT LEAST ONE NUMBER");
		}
	
	
	double min = *min_element(sample.begin(), sample.end());
	cout << min << " ";
	double max = *max_element(sample.begin(), sample.end());
	cout << max << " ";
	double average = accumulate(sample.begin(), sample.end(), 0.0) / sample.size();
	if(type_of_the_function == "integers-only" || type_of_the_function == "strict:integers-only")
	{
		cout << setprecision(2) << average << endl;
	}
	else cout << setprecision(4) << average << endl;
	} catch (Exception ex) {
		cout << ex.get_error() << endl;
	}
	






	return 0;
}
