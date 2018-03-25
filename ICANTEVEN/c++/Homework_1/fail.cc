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

class NumbersException {
	string errormsg; 

	public:
		NumbersException(string message) : errormsg(message) {}
	string get_err_msg() {
		return errormsg;
		}
};

int main()
{
	try {
			
	vector<double> calc;
	string input;
	cin >> input;
	if(input == "END") 
	{
		throw NumbersException("ERR: PROVIDE AT LEAST ONE NUMBER");
	}

	string type;
	if(input == "strict" || input == "integers-only" || input == "strict:integers-only") 
	{
		type = input;
		cin >> input;
	}

	while(input != "END")
	{
		istringstream my_stream(input);
		double token;
		cin >> input;
		if(type == "strict")
		{
			if(!my_stream.fail()) 
			{
				calc.push_back(token);
			} else 
			{
				throw NumbersException("ERR: PROVIDE ONLY NUMBERS");	
			}
		}
		else 
		{
			if(!my_stream.fail()) {
				calc.push_back(token);	
			}
		}
		cin >> input;

	}
		double max, min, avg;
 
        max = calc.front();
        min = calc.front();
        avg = calc.front();
 
        for (int i = 1; i < calc.size(); i++) {
            if(max < calc[i]) {
                max = calc[i];
            }
           
            if(min > calc[i]) {
                min = calc[i];
            }
           
            avg += calc[i];
        }
 
        avg = avg / calc.size();
	cout << min << " " << max << " " << setprecision(4) << avg << endl;
	} catch(NumbersException ex) {
		cout << ex.get_err_msg() << endl;
	}

return 0;






}

