#include <iostream>
#include <string>
#include <sstream>
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
        	return !operator==(other);
        }

        Iterator& operator++() {
        	current_ = current_->next_;
        	return *this;
        }

        Iterator operator++(int) {
        	Iterator previous = *this;
        	++(*this);
        	return previous;
        }

        int& operator[](const int& index) {
        	return current_->data_[index];
        }

        int size() {
        	return current_->size_;
        }

        void show() {
        	for(int i = 0; i < size(); i++) {
                if (i != 0) {
                    cout << " ";
                }
        		cout << current_->data_[i];
        	}
        }
        
        double average() {
        	return (double)sum() / size();
        }
        
        double median() {
        	if(size() % 2 != 0) {
        		return current_->data_[(size() - 1) / 2];
        	}
        	else {
        		return (current_->data_[(size() / 2) - 1] + current_->data_[size() / 2]) / (double)2;
        	}
        }
        
        int sum() {
        	int sum = 0;
        	for(int i = 0; i < size(); i++) {
        		sum += current_->data_[i];
        	}
        	return sum;
        }
        
        Iterator& ordered(bool ascending = true) {
        	if(ascending) {
        		int sorted = 0;
        		while(!sorted) {
        			sorted = 1;
        			for(int i = 0; i < size() - 1; i++) {
        				if(current_->data_[i] > current_->data_[i + 1]) {
        					int tmp = current_->data_[i];
        					current_->data_[i] = current_->data_[i + 1];
        					current_->data_[i + 1] = tmp;
        					sorted = 0;
        				}
        			}
        		}
        	}
        	else {
        		int sorted = 0;
        		while(!sorted) {
        			sorted = 1;
        			for(int i = 0; i < size() - 1; i++) {
        				if(current_->data_[i] < current_->data_[i + 1]) {
        					int tmp = current_->data_[i];
        					current_->data_[i] = current_->data_[i + 1];
        					current_->data_[i + 1] = tmp;
        					sorted = 0;
        				}
        			}
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
    :	size_ (other.size_)
    {
    	ArrayNode* curr_other = other.head_->next_;
    	ListOfArrays new_list;
    	while(curr_other != other.head_) {
    		new_list.push(curr_other->data_, 0, curr_other->size_);
    		curr_other = curr_other->next_;
    	}

    	this->head_ = new_list.head_;
    	this->size_ = new_list.size_;
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
    	int* tmp = new int[length - position];
    	for(int i = position; i < length; i++) {
    		tmp[i - position] = array[i];
    	}
    	ArrayNode* new_node = new ArrayNode(tmp, length - position);
    	head_->prev_->next_ = new_node;
    	new_node->prev_ = head_->prev_;
    	head_->prev_ = new_node;
    	new_node->next_ = head_;

    	size_++;
    }

    void averages(double averages[]) {
    	int i = 0;
    	for(Iterator it = begin(); it != end(); it++) {
    		averages[i] = it.average();
    		i++;
    	}
    }

    void medians(double medians[]) {
    	int i = 0;
    	for(Iterator it = begin(); it != end(); it++) {
    		medians[i] = it.median();
            i++;
    	}
    }
    
    void sizes(int sizes[]) {
    	int i = 0;
    	for(Iterator it = begin(); it != end(); it++) {
    		sizes[i] = it.size();
    		i++;
    	}
    }
    
    void sums(int sums[]) {
    	int i = 0;
    	for(Iterator it = begin(); it != end(); it++) {
    		sums[i] = it.sum();
    		i++;
    	}
    }

    Iterator begin() {
    	Iterator tmp(*this, head_->next_);
    	return tmp;
    }

    Iterator end() {
    	Iterator tmp(*this, head_);
    	return tmp;
    }

    ListOfArrays& ordered(bool ascending = true) {
    	for(Iterator it = begin(); it != end(); it++) {
    		it.ordered(ascending);
    	}
    	int sorted = 0;
    	while(!sorted) {
    		sorted = 1;
    		Iterator tmp = begin();
    		for(Iterator it = ++begin(); it != end(); it++) {
    			int min_size = (it.size() > tmp.size())? tmp.size():it.size();

                int i;
                for(i = 0; i < min_size; i++) {

    				if( (ascending == 1 && tmp[i] > it[i]) ||
                        (ascending == 0 && tmp[i] < it[i]) ) {

    					int* arr = tmp.current_->data_;
                        int tmp_size = tmp.current_->size_;

                        tmp.current_->data_ = new int[it.size()];
                        for(int j = 0; j < it.size(); j++) {
                            tmp.current_->data_[j] = it.current_->data_[j];
                        }
                        tmp.current_->size_ = it.size();

                        it.current_->data_ = new int[tmp_size];
                        for(int j = 0; j < tmp_size; j++) {
                            it.current_->data_[j] = arr[j];
                        }
                        it.current_->size_ = tmp_size;

    					sorted = 0;
                        break;
    				}
                    if(tmp[i] != it[i]) {
                        break;
                    }
                }
                if(sorted == 1 && i == min_size) {
    				if( (ascending == 1 && tmp.size() > it.size()) ||
                        (ascending == 0 && tmp.size() < it.size()) ) {

                        int* arr = tmp.current_->data_;
                        int tmp_size = tmp.current_->size_;

                        tmp.current_->data_ = new int[it.size()];
                        for(int j = 0; j < it.size(); j++) {
                            tmp.current_->data_[j] = it.current_->data_[j];
                        }
                        tmp.current_->size_ = it.size();

                        it.current_->data_ = new int[tmp_size];
                        for(int j = 0; j < tmp_size; j++) {
                            it.current_->data_[j] = arr[j];
                        }
                        it.current_->size_ = tmp_size;

                        sorted = 0;
    				}
    			}
                tmp++;
    		}
    	}
        return *this;
    }

    ListOfArrays& operator*=(const int& coef) {
    	for(Iterator it = begin(); it != end(); it++) {
    		for(int i = 0; i < it.size(); i++) {
    			it[i] *= coef;
    		}
    	}
        return *this;
    }

    ListOfArrays& operator+=(const int& value) {
    	for(Iterator it = begin(); it != end(); it++) {
    		for(int i = 0; i < it.size(); i++) {
    			it[i] += value;
    		}
    	}
        return *this;
    }

    void show() {
    	for(Iterator it = begin(); it != end(); it++) {
    		it.show();
            if(it.current_->next_ != end().current_) {
                cout << "; ";
            }
    	}
    }
};

int main(int argc, char const *argv[]) {
	
    ListOfArrays list;

    string input;
    
    cout << "> ";
    getline(cin, input);
    if (input == "quit") {
        return 0;
    }

    string arrays;
    istringstream in(input);

    while(getline(in, arrays, ';')) {
        istringstream stream_num(arrays);
        int* arr = new int[1];
        int size = 0;
        while(stream_num >> arr[size]) {
            int* tmp = arr;
            arr = new int[size++];
            for(int i = 0 ; i < size; i++) {
                arr[i] = tmp[i];
            }
            delete [] tmp;
        }
        if(size != 0) {
            list.push(arr, 0, size);
        }
    }

    while(1) {

        ListOfArrays l(list);
        ListOfArrays::Iterator it = l.end();

        cout << "> ";
        getline(cin, input);
        if (input == "quit") {
            break;
        }

        istringstream in(input);
        string commands;

        while(getline(in, commands, '.')) {
            istringstream stream_com(commands);

            string command;
            string param;
            
            getline(stream_com, command, ':');

            getline(stream_com, param);

            if(!command.compare("ordered")) {
                bool ascending = true;

                if(!commands.compare("true")) {
                    ascending = true;
                }
                else if(!param.compare("false")) {
                    ascending = false;
                }

                if(it != l.end()) {
                    it.ordered(ascending);
                }
                else {
                    l.ordered(ascending);
                }
            }
            else if(!command.compare("mul")) {
                int n = stoi(param);

                if(it == l.end()) {
                    l *= n;
                }
            }
            else if(!command.compare("add")) {
                int n = stoi(param);

                if(it == l.end()) {
                    l += n;
                }
            }
            else if(!command.compare("show")) {
                if(it != l.end()) {
                    it.show();
                }
                else {
                    l.show();
                }
                cout << endl;
            }
            else if(!command.compare("size")) {
                if(it != l.end()) {
                    cout << it.size() << endl;
                }
                else {
                    cout << l.size() << endl;;
                }
            }
            else if(!command.compare("averages")) {
                double* avrg = new double[l.size()];
                l.averages(avrg);
                for(int i = 0; i < l.size(); i++) {
                    cout << avrg[i] << " ";
                }
                cout << endl;
            }
            else if(!command.compare("medians")) {
                double* med = new double[l.size()];
                l.medians(med);
                for(int i = 0; i < l.size(); i++) {
                    cout << med[i] << " ";
                }
                cout << endl;
            }
            else if(!command.compare("sums")) {
                int* sums = new int[l.size()];
                l.sums(sums);
                for(int i = 0; i < l.size(); i++) {
                    cout << sums[i] << " ";
                }
                cout << endl;
            }
            else if(!command.compare("sizes")) {
                int* sizes = new int[l.size()];
                l.sizes(sizes);
                for(int i = 0; i < l.size(); i++) {
                    cout << sizes[i] << " ";
                }
                cout << endl;
            }
            else if(!command.compare("begin")) {
                if(it == l.end()) {
                    it++;
                }
            }
            else if(!command.compare("next")) {
                if(it == l.end() || ++it == l.end()) {
                    cout << "ERROR: End of iteration" << endl;
                    break;
                }
            }
            else if(!command.compare("at")) {
                int n = stoi(param);
                if(n < it.size() && n >= 0) {
                    cout << it[n] << endl;
                }
                else {
                    cout << "ERROR: Index out of bounds" << endl;
                }
            }
            else if(!command.compare("average")) {
                cout << it.average() << endl;
            }
            else if(!command.compare("median")) {
                cout << it.median() << endl;
            }
            else if(!command.compare("sum")) {
                cout << it.sum() << endl;
            }
            else {
                cout << "ERROR: Unknown operation" << endl;
            }
        }
	}

	return 0;
}

    
     

