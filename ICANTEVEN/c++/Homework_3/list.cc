#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <stdlib.h>
using namespace std;

class ListOfArrays {

    class ArrayNode {

        public:

        int* data_;
        int size_;
        ArrayNode* prev_;
        ArrayNode* next_;

        ArrayNode(int* data, int size)
            : data_(data), size_(size), next_(0), prev_(0) {}

        ~ArrayNode() {
            delete [] data_;
        }

    };

    ArrayNode* head_;
    int size_;
//**************************************************************************************************
    public:

    class Iterator {

        friend class ListOfArrays;

        ListOfArrays& list_;
        ArrayNode* current_;

        public:

        Iterator(ListOfArrays& list, ArrayNode* current)
            : list_(list), current_(current) {}

        bool operator==(const Iterator& other) {
		return current_ == other.current_;
	}
	
        bool operator!=(const Iterator& other) {
		return ! operator==(other);
	}

        Iterator& operator++() {
		current_ = current_ -> next_;
		return *this;
	}

        Iterator operator++(int) {
		Iterator previous(list_, current_);
		current_ = current_ -> next_;
		return previous;
	}

        int& operator[](const int& index) {
		return current_ -> data_[index];
	}

        int size() {
		return current_ -> size_;
	}


        void show() {
		for(int i = 0; i < size(); i++) {
			if (i > 0) cout << " ";
			cout << current_ -> data_[i];
		}
	}
        

        double average() {
		return (double)sum() / size();
	}
        

        double median() {
		if(size() % 2 != 0) {
			return current_ -> data_[size() / 2];
		}
		else {
			return ((current_ -> data_[(size() / 2) - 1] + current_ -> data_[size() / 2]) / (double)2); 
		}
	}
        

        int sum() {
		int sum = 0;
		for(int i = 0; i < size(); i++) {
			sum = sum + current_ -> data_[i];
		}
		return sum;
	}	
        
 
        Iterator& ordered(bool ascending = true) {
		if(ascending) {
			int x;
			int j;
			for(int i = 1; i < size() - 1; i ++) {
				x = current_ -> data_[i];
				for(j = i - 1; j >= 0; j--) {
					if(x < current_ -> data_[j]) 
					current_ -> data_[j + 1] = current_ -> data_[j];
					else break;
				}
				current_ -> data_[j + 1] = x;
			}
		}
		else if(!ascending) {
			int x;
			int j;
			for(int i = 1; i < size() - 1; i ++) {
				x = current_ -> data_[i];
				for(j = i - 1; j >= 0; j--) {
					if(x > current_ -> data_[j]) 
					current_ -> data_[j + 1] = current_ -> data_[j];
					else break;
				}
				current_ -> data_[j + 1] = x;
			}
		}
		return *this;
		
	}


    };

    ListOfArrays()
            : size_(0), head_(new ArrayNode(0, 0)) {
        head_->next_ = head_;
        head_->prev_ = head_;
    }

    	ListOfArrays(const ListOfArrays& other)
	: size_(other.size_) {
		ArrayNode* tmp = other.head_ -> next_;
		ListOfArrays sheet;
		while(tmp != other.head_) {
			sheet.push(tmp -> data_, 0, tmp -> size_);
			tmp = tmp->next_;
		}

		this -> head_ = sheet.head_;
		this -> size_ = sheet.size_;
	}

	ListOfArrays& operator=(const ListOfArrays& other) {
		size_ = other.size_;
		head_ = other.head_;
		return *this;
	}


	int size() {
		return size_;
	}


	void push(int array[], int position, int length) {
		int* arr = new int[length - position];
		for(int i = position; i <= length + 1; i++) {
			arr[i - position] = array[i];
		}

		ArrayNode* node = new ArrayNode(arr, length - position);
		head_ -> prev_ -> next_ = node;
		node -> prev_ = head_ -> prev_;
		head_ -> prev_ = node;
		node -> next_ = head_;
		size_++;
	}


	void averages(double averages[]) {
		int i = 0;
        for (Iterator it = begin();it !=end();++i, ++it) {
            averages[i] = it.average();
        }
        for (int k = 0; k < i; k++) {
            cout << averages[k] << " ";    
        }
        cout << endl;
	}	


	void medians(double medians[]) {
		int i = 0;
		for(Iterator it = begin(); it != end(); it++,i++) {
			medians[i] = it.median();
		}
	}
    

	void sizes(int sizes[]) {
		int i = 0;
		for(Iterator it = begin(); it != end(); it++,i++) {
			sizes[i] = it.size();
		}
	}
    
	void sums(int sums[]) {
		int i = 0;
		for(Iterator it = begin(); it != end(); it++,i++) {
			sums[i] = it.sum();
		}
	}


	Iterator begin() {
		return Iterator(*this, head_ -> next_);
	} 


	Iterator end() {
		return Iterator(*this, head_);
	}


	ListOfArrays& ordered(bool ascending = true) {
		for(Iterator it = begin(); it != end(); it++) {
			it.ordered(ascending);
		}
		bool sorted = true;
		while(sorted) {
			sorted = false;
			Iterator extra = begin();
			//for(Iterator it = ++begin();)
			for(Iterator it = begin(); it != end(); it++) {
				int minimal_size = 0;
				if(it.size() > extra.size()) {
					minimal_size = extra.size();
				} else minimal_size = it.size();

				for(int i = 0; i < minimal_size; i++) {
					if(extra[i] > it[i]) {
						int* helper = extra.current_ -> data_;
						extra.current_ -> data_ = it.current_ -> data_;
						it.current_ -> data_ = helper;
		
						int extra_size = extra.current_ -> size_;
						extra.current_ -> size_ = it.current_ -> size_;
						it.current_ -> size_ = extra_size;

						extra.current_ -> next_ = it.current_ -> next_;
						it.current_ -> next_ -> prev_ = extra.current_;
						extra.current_ -> prev_ -> next_ = it.current_;
						it.current_ -> prev_ = extra.current_ -> prev_;

						extra.current_ -> prev_ = it.current_;
						it.current_ -> next_ = extra.current_;
						sorted == false;
						break;
					}
					if(extra[i] != it[i]) { break;}
				}
				if(sorted == true && extra.size() < it.size()) {
					int* helper = extra.current_ -> data_;
					extra.current_ -> data_ = it.current_ -> data_;
					it.current_ -> data_ = helper;
					
					extra.current_ -> next_ = it.current_ -> next_;
					it.current_ -> next_ -> prev_ = extra.current_;
					extra.current_ -> prev_ -> next_ = it.current_;
					it.current_ -> prev_ = extra.current_ -> prev_;

					extra.current_ -> prev_ = it.current_;
					it.current_ -> next_ = extra.current_;
					sorted == false;
				}						
			}		
		}
		return *this;
	}


	ListOfArrays& operator*=(const int& coef) {
		for(Iterator it = begin(); it != end(); it++) {
			for(int i = 0; i < it.size(); i++) {
				it[i] = it[i] * coef;
			}
		}
		return *this;
	}


	ListOfArrays& operator+=(const int& value) {
		for(Iterator it = begin(); it != end(); it++) {
			for(int i = 0; i < it.size(); i++) {
				it[i] = it[i] + value;
			}
		}
		return *this;
	}
	

	void show() {
		for(Iterator it = begin(); it != end(); it++) {
			//it.ordered();
			if(it != begin()) cout << " ";
			it.show();
			if(it.current_->next_ != end().current_) {
				cout << ";";
			}
		}
	}
};



int main() {

	ListOfArrays new_list;	

	string input;
	cout << "> ";
    	getline(cin, input);
	
    	if (input == "quit") {
        	return 0;
    	}
        stringstream in(input);
    	string arr;
    	while(getline(in, input,';')){
		int masiv[100];
        	stringstream list(input);
		int i = 0;
            	while(getline(list, arr,' ')){
            		istringstream number(arr);
            		int value;
            		number >> value;
			if(!number.fail()) {
            			masiv[i] = value;
			} else i--;
			i++;
        	}
		new_list.push(masiv,0,i);
    	}
		
	while(1) {

        ListOfArrays list1(new_list);
        ListOfArrays::Iterator it = list1.end();

        cout << "> ";
        getline(cin, input);
        if (input == "quit") {
            break;
        }

        istringstream in(input);
        string operations;

        while(getline(in, operations, '.')) {
            istringstream notice(operations);

            string command;
            string elements;
            
            getline(notice, command, ':');

            getline(notice, elements);

            if(command == "ordered") {
                bool ascending = true;

                if(command ==  "true") {
                    ascending = true;
                }
                else if(command == "false") {
                    ascending = false;
                }

                if(it != list1.end()) {
                    it.ordered(ascending);
                }
                else {
                    list1.ordered(ascending);
                }
            }
            
            
            else if(command == "show") {
                if(it != list1.end()) {
                    it.show();
                }
                else {
                    list1.show();
                }
                cout << endl;
            }
            else if(command == "size") {
                if(it != list1.end()) {
                    cout << it.size() << endl;
                }
                else {
                    cout << list1.size() << endl;;
                }
            }
            else if(command == "averages") {
                double* avrg = new double[list1.size()];
                list1.averages(avrg);
                for(int i = 0; i < list1.size(); i++) {
                    cout << avrg[i] << " ";
                }
                cout << endl;
            }
            else if(command == "medians") {
                double* med = new double[list1.size()];
                list1.medians(med);
                for(int i = 0; i < list1.size(); i++) {
                    cout << med[i] << " ";
                }
                cout << endl;
            }
            else if(command == "sums") {
                int* sums = new int[list1.size()];
                list1.sums(sums);
                for(int i = 0; i < list1.size(); i++) {
                    cout << sums[i] << " ";
                }
                cout << endl;
            }
            else if(command == "sizes") {
                int* sizes = new int[list1.size()];
                list1.sizes(sizes);
                for(int i = 0; i < list1.size(); i++) {
                    cout << sizes[i] << " ";
                }
                cout << endl;
            }
            else if(command == "begin") {
                if(it == list1.end()) {
                    it++;
                }
            }
            else if(command == "next") {
                if(it == list1.end() || ++it == list1.end()) {
                    cout << "ERROR: End of iteration" << endl;
                    break;
                }
            }
		else if(command == "add") {
                int number = stoi(elements);

                if(it == list1.end()) {
                    list1 += number;
                }
            }
		else if(command == "mul") {
                int number = stoi(elements);

                if(it == list1.end()) {
                    list1 *= number;
                }
            }
	   else if(command == "at") {
                int number = stoi(elements);
                if(number < it.size() && number >= 0) {
                    cout << it[number] << endl;
                }
                else {
                    cout << "ERROR: Index out of bounds" << endl;
                }
            }
            else if(command == "average") {
                cout << it.average() << endl;
            }
            else if(command == "median") {
                cout << it.median() << endl;
            }
            else if(command == "sum") {
                cout << it.sum() << endl;
            }
            else {
                cout << "ERROR: Unknown operation" << endl;
            }
        }
	}
	return 0;
	
}

		


