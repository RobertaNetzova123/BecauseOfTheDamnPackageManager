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
