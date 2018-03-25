#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
 
using namespace std;
 
class NumbersException {
    string err_msg_;
   
    public:
        NumbersException(string message) : err_msg_(message) {}
   
        string get_err_msg() {
            return err_msg_;
        }
};
 
int main() {
    try {
        vector<double> numbers;
       
        string input;
       
        cin >> input;
       
        if (input == "END") {
                throw NumbersException("ERR: PROVIDE AT LEAST ONE NUMBER");
        }
       
        string option;
       
        if (input == "strict" || input == "integers-only" || input == "strict:integers-only") {
            option = input;
           
            cin >> input;
        }
       
        while(input != "END") 
	{
            istringstream in(input);
 
            double value;
 
            in >> value;
           
            if (option == "strict") 
	    {
        	        if (!in.fail()) 
			{
        	            numbers.push_back(value);
                	}
                else 
		{
                    throw NumbersException("ERR: PROVIDE ONLY NUMBERS");
                }
            }


            else if (option == "integers-only") 
	    {
                	if (!in.fail()) 
			{
                    		numbers.push_back(floor(value));
                	}
            }

            else if (option == "strict:integers-only") 
	    {
                	if (in.fail()) 
			{
                    		throw NumbersException("ERR: PROVIDE ONLY NUMBERS");
               		}
               
                	if (floor(value) == value) 
			{
                    		numbers.push_back(value);
                	}
                	else 
			{
                    		throw NumbersException("ERR: PROVIDE ONLY INTEGERS");
                	}
            }
            else 
	    {
                if (!in.fail()) 
		{
                    numbers.push_back(value);
                }
            }
           
            cin >> input;
        }
       
        if (numbers.empty()) {
            throw NumbersException("ERR: PROVIDE AT LEAST ONE NUMBER");
        }
       
        double max, min, avg;
 
        max = numbers.front();
        min = numbers.front();
        avg = numbers.front();
 
        for (int i = 1; i < numbers.size(); i++) {
            if(max < numbers[i]) {
                max = numbers[i];
            }
           
            if(min > numbers[i]) {
                min = numbers[i];
            }
           
            avg += numbers[i];
        }
 
        avg = avg / numbers.size();
       
        if (option == "integers-only") {
            avg = floor(avg);
        }
 
        cout << min << " " << max << " " << setprecision(4) << avg << endl;
    } catch (NumbersException ex) {
        cout << ex.get_err_msg() << endl;
    }
   
    return 0;
}
