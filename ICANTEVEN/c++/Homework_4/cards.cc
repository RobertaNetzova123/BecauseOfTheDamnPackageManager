#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iterator>
#include <iomanip>
#include <numeric>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Exception {
    string error_;

public:
    Exception(string msg)
    : error_(msg) {}

    string get_error() {
        return error_;
    }
};
//--------------------------------------------------
class DeckOfCards;
//--------------------------------------------------
class Operation {
protected:
    string name_;
    DeckOfCards& deck_;
    int cards_number;

        public:
            Operation(DeckOfCards& deck, string name)
            : deck_(deck), name_(name) {}

            string get_name() const
            {
                return name_;
            }

        virtual void execute() = 0;
};
//-------------------------------------------------------------------------------

class DeckOfCards {

public:
    vector<string> cards_;
	vector<string> first_cards_;
    vector<Operation*> operations_;
	string curr_game_;
    DeckOfCards(vector<string> deck)
    : first_cards_(deck)  {}

    void add_operation(Operation* operation);
    Operation* get_operation(string name);
    void run();
    //void deal();
};


void DeckOfCards::add_operation(Operation* operation) {
    operations_.push_back(operation);
}

Operation* DeckOfCards::get_operation(string name) {
    for(vector<Operation*>::iterator it = operations_.begin(); it != operations_.end(); ++it) {
        if(name == (*it) -> get_name()) {
            return *it;
        }
    }
    throw Exception("ERROR: Unknown operation");
}

void DeckOfCards::run() {
    string card;
    while(1) {
		try {
		    cout << "> ";
		    cin >> card;
			if(card == "quit") break;
		    Operation* operation = DeckOfCards::get_operation(card);
		    operation -> execute();
		} catch (Exception& e) {
			cout << e.get_error() << endl;
		}
    }
}

//-----------------------------------------------------------------------------------

class Santase: public Operation {

protected:
    int cards_number = 24;
public:
    Santase(DeckOfCards& deck)
    : Operation(deck, "Santase") {}

    void execute();
    //void deal();
};

void Santase::execute() {
	vector<char> ranks = {'9', 'J', 'Q', 'K', '1', 'A'};
	for(int i = 0; i < deck_.first_cards_.size(); i++) {
		for(int j = 0; j < ranks.size(); j++) {
			if(deck_.first_cards_[i][1] == ranks[j]) {
				deck_.cards_.push_back(deck_.first_cards_[i]);
				break;
			}
		}
	}
	if (cards_number > deck_.cards_.size()) {
            throw Exception("ERROR: Not enough cards for Santase");
        }
	deck_.curr_game_ = "Santase";
}

//-----------------------------------------------------------------------------------

class War: public Operation {

protected:
    int cards_number = 52;
public:
    War(DeckOfCards& deck)
    : Operation(deck, "War") {}

    void execute();
    //void deal();

};

void War::execute() {
    //here more

		vector<char> ranks = {'2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K', 'A'};
		for(int i = 0; i < deck_.first_cards_.size(); i++) {
			for(int j = 0; j < ranks.size(); j++) {
				if(deck_.first_cards_[i][1] == ranks[j]) {
					deck_.cards_.push_back(deck_.first_cards_[i]);
					break;
				}
			}
		}
		if(cards_number > deck_.cards_.size()) {
            throw Exception("ERROR: Not enough cards for War");
        }
		deck_.curr_game_ = "War";
}

//-----------------------------------------------------------------------------------

class Belote: public Operation {

protected:
    int cards_number = 32;
public:
    Belote(DeckOfCards& deck)
    : Operation(deck, "Belote") {}

    void execute();
    void deal();
};

void Belote::execute() {
	vector<char> ranks = {'7', '8', '9', 'J', 'Q', 'K', '1', 'A'};
		for(int i = 0; i < deck_.first_cards_.size(); i++) {
			for(int j = 0; j < ranks.size(); j++) {
				if(deck_.first_cards_[i][1] == ranks[j]) {
					deck_.cards_.push_back(deck_.first_cards_[i]);
					break;
				}
			}
		}
	if (cards_number > deck_.cards_.size()) {
            throw Exception("ERROR: Not enough cards for Belote");
        }
	deck_.curr_game_ = "Belote";
}

//-----------------------------------------------------------------------------------

class Size : public Operation {

public:
    Size(DeckOfCards& deck)
    : Operation(deck, "size") {}

    void execute();
};

void Size::execute() {
    if(deck_.curr_game_ == "") throw Exception("ERROR: No deck");
    int cards = deck_.cards_.size();
    cout << cards << endl;
}
//-----------------------------------------------------------------------------------

class Draw_top_card : public Operation {

public:
    Draw_top_card(DeckOfCards& deck)
    : Operation(deck, "draw_top_card") {}

    void execute();
};

void Draw_top_card::execute() {
    int cards = deck_.cards_.size();
    if(deck_.curr_game_ == "") throw Exception("ERROR: No deck");
	if(cards == 0) throw Exception("ERROR: Not Enough cards in deck");
    //Top_card:: void execute();
    string pick_up = deck_.cards_.front();
    deck_.cards_.erase(deck_.cards_.begin());
    cout << pick_up << endl;
}
//-----------------------------------------------------------------------------------

class Top_card : public Operation {

public:
    Top_card(DeckOfCards& deck)
    : Operation(deck, "top_card") {}

    void execute();
};

void Top_card::execute() {
    int cards = deck_.cards_.size();
    if(deck_.curr_game_ == "") throw Exception("ERROR: No deck");
	if(cards == 0) throw Exception("ERROR: Not Enough cards in deck");
    cout << deck_.cards_.front() << endl;
}

//-----------------------------------------------------------------------------------

class Draw_bottom_card : public Operation {

public:
    Draw_bottom_card(DeckOfCards& deck)
    : Operation(deck, "draw_bottom_card") {}

    void execute();
};

void Draw_bottom_card::execute() {
    int cards = deck_.cards_.size();
	if(deck_.curr_game_ == "") throw Exception("ERROR: No deck");
    if(cards == 0) throw Exception("ERROR: Not Enough cards in deck");
    //Top_card:: void execute();
    string pick_up = deck_.cards_.back();
    //deck_.cards_.erase(deck_.cards_.end()); ??
    deck_.cards_.pop_back();
    cout << pick_up << endl;
}

//-----------------------------------------------------------------------------------

class Bottom_card : public Operation {

public:
    Bottom_card(DeckOfCards& deck)
    : Operation(deck, "bottom_card") {}

    void execute();
};

void Bottom_card::execute() {
    int cards = deck_.cards_.size();
	if(deck_.curr_game_ == "") throw Exception("ERROR: No deck");
    if(cards == 0) throw Exception("ERROR: Not Enough cards in deck");
    cout << deck_.cards_.back() << endl;
}

//-----------------------------------------------------------------------------------

class Shuffle : public Operation {

public:
    Shuffle(DeckOfCards& deck)
    : Operation(deck, "shuffle") {}

    void execute();
};

void Shuffle::execute() {
	if(deck_.curr_game_ == "") throw Exception("ERROR: No deck");
    srand(time(0));
    random_shuffle(deck_.cards_.begin(), deck_.cards_.end());
    for(vector<string>::iterator it = deck_.cards_.begin(); it != deck_.cards_.end(); ++it) {
        cout << *it << endl;
    }
}

class Deal : public Operation {

public:
    Deal(DeckOfCards& deck)
    : Operation(deck, "deal") {}

    void execute();
};

//working?
void Deal::execute() {
    int times = 0;
    if(deck_.curr_game_ == "Santase") times = 6;
    else if(deck_.curr_game_  == "Belote") times = 8;
    else if(deck_.curr_game_  == "War") times = 26;
	else throw Exception("ERROR: No deck");
	if(deck_.cards_.size() < times) throw Exception("ERROR: Not enough cards in deck");
    for(int i = 0; i < times; i++) {
        cout << deck_.cards_.front() << " ";
        deck_.cards_.erase(deck_.cards_.begin());
    }
	cout << endl;
}
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------

int main() {

    cout << "> ";
    string cards;
    getline(cin,cards);
    istringstream in(cards);
    vector<string> now;
    string token;
    in >> token;
    while(!in.fail()) {
        now.push_back(token);
        in >> token;
    }

    DeckOfCards deck(now);
    deck.add_operation(new Santase(deck));
    deck.add_operation(new Belote(deck));
    deck.add_operation(new War(deck));
    deck.add_operation(new Size(deck));
    deck.add_operation(new Draw_top_card(deck));
    deck.add_operation(new Draw_bottom_card(deck));
    deck.add_operation(new Top_card(deck));
    deck.add_operation(new Bottom_card(deck));
    deck.add_operation(new Deal(deck));
	deck.add_operation(new Shuffle(deck));

    deck.run();

    return 0;
}
