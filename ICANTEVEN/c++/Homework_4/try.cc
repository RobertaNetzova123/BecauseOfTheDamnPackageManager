#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class DeckError 
{
	string message_;
public:
	DeckError(string message)
	: message_(message) {}
	
	string get_message() const {
		return message_;
	}
};

class Deck;

class Operation
{
		string name_;

		protected:

			Deck& deck_;

		public:

			Operation(Deck& deck, string name)
			: deck_(deck), name_(name) {}

			string get_name() const 
			{
				return name_;
			}
	
		virtual void execute() = 0;
};


class Deck
{
	protected:

		vector<string> cards_;	
		vector<Operation*> operations_;
	
	public:

		void push(string card)
		{
			cards_.push_back(card);
		}
		
		void add_operation(Operation* operation)
		{
			operations_.push_back(operation);
		}

		Operation* find_operation(string name)
		{
			for (vector<Operation*>::iterator it = operations_.begin(); it != operations_.end(); ++it)
			{
			
				if ((*it) -> get_name() == name)
				{
					return *it;
				}
			}

			throw DeckError("Unknown operation");
		}

		void run()
		{
			string cards;

			getline(cin,cards);
			istringstream line(cards);

			while(!line.eof())
			{	
				string card;
				getline(line,card,' ');
				push(card);		
			}
			
		}

		void print()
		{
			for(vector<string>::iterator it = cards_.begin(); it != cards_.end(); ++it)
			cout << *it << endl;
		}
};

class Santase : public Operation
{
	Deck deck_;
	
	public:

	Santase(Deck& deck) : deck_(deck),Operation(deck_,"Santase") {}

	void execute()
	{
		cout << "Hello Santase!" << endl;
	}
};

class Belote : public Operation
{
	Deck deck_;

	public:

	Belote(Deck& deck) : deck_(deck),Operation(deck_,"Belote") {}

	void execute()
	{
		cout << "Hello Belote!" << endl;
	}
};

class War : public Operation
{
	Deck deck_;
	
	public:
	
	War(Deck& deck) : deck_(deck), Operation(deck_,"War") {}
	
	void execute()
	{
		cout << "Hello War!" << endl;
	}
};

int main()
{
	Deck deck;
	deck.add_operation(new Santase(deck));
	deck.add_operation(new Belote(deck));
	deck.add_operation(new War(deck));
	
	deck.run();
	deck.print();

	return 0;
}
