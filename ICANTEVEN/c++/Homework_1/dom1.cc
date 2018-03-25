#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <sstream>
#include <iterator>
#include <iomanip>
#include <numeric>

using namespace std;
const char ending_word[] = "END";
class exeption_not_a_number {};
class exeption_not_a_integer {};
class exeption_no_number {};

int main() {
try {

  vector<string> full_vector;
  vector<double> double_vector;
  double max, min, sum;
  int j = 0;
  string line;

  do {
    getline(cin, line);
    if (cin.fail()) {
      throw exeption_not_a_number();
      break;
    }
    string buffer;
    stringstream new_stream(line);

    while (new_stream >> buffer && line != ending_word){
      full_vector.push_back(buffer);
       double current_double;
       istringstream temp_stream(buffer);
       if (*full_vector.begin() == "strict" ){
         temp_stream >> current_double;
         cout.precision(4);
         if (temp_stream.fail() && buffer != *full_vector.begin()){
          throw exeption_not_a_number();
           // return 0;
         }
       } else if(*full_vector.begin() == "strict:integers-only"){
         temp_stream >> current_double;
         if(current_double != (int) current_double){
           cout << "ERR: PROVIDE ONLY INTEGERS" << endl;
           // throw exeption_not_a_number();
           return 0;
         }
         cout << fixed << setprecision(0);
         if (temp_stream.fail() && buffer != *full_vector.begin()){
           throw exeption_not_a_number();
         }
       } else if(*full_vector.begin() == "integers-only"){
         temp_stream >> current_double;
         cout << fixed << setprecision(0);
       } else {
         cout.precision(4);
         temp_stream >> current_double;
       }
       if (!temp_stream.fail() && temp_stream.eof()){
        double_vector.push_back(current_double);
        max = *max_element(double_vector.begin(), double_vector.end());
        min = *min_element(double_vector.begin(), double_vector.end());
        sum += double_vector[j];
        j++;
      }
    }

  } while (!cin.eof() && line != ending_word);
 if(double_vector.size() == 0){
   throw exeption_no_number();

}
cout << min << " " << max << " " << sum/double_vector.size() << endl;
// cout << min_val << " " << max_val << " " << sum/double_vector.size() << endl;
} catch(exeption_not_a_number ex) {
    cout << "ERR: PROVIDE ONLY NUMBERS" << endl;
    return 0;
} catch (exeption_not_a_integer ex2){
    cout << "ERR: PROVIDE ONLY INTEGERS" << endl;
    return 0;
}catch (exeption_no_number ex3){
    cout << "ERR: PROVIDE AT LEAST ONE NUMBER" << endl;
    return 0;
}

return 0;
}
