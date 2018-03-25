#include <iostream>

using namespace std;

class Exception {};

class Vector {
	int capacity_;
	int size_;
	int* buffer_;

public:

	Vector(int capacity = 10, int size = 0)
	: capacity_(capacity), size_(size), buffer_(new int[capacity]) {}
	
	~Vector() {
		delete [] buffer_;
	}

	//връща размера на вектора(броя елементи във вектора)
	int size() const {
		return size_; 
	}

	//връща true когато вектора е празен (т.е. когато size() == 0)
	bool empty() const {
		return size_ == 0;
	}

	//връща препратка към n-тия елемент на вектора (елемента с индекс n)
	int& operator[](int n) {
		if(!empty()) {
			if(n < size_) {
				return buffer_[n];
			}
		}
		throw Exception();
	}
	
	//връща константтна препратка към n-тия елемент на вектора (елемента с индекс n)
	const int& operator[](int n) const{
		if(!empty()) {
			if(n < size_) {
				return buffer_[n];
			}
		}
		throw Exception();
	}

	//изтрива всички елементи на вектора
	void clear() {
		size_ == 0;
	}		
	
	//връща броя елементи за които е задалена памт. Методът capacity() винаги връща стойност, 		която е по-голяма или равна на size()
	int capacity() const {
		if(capacity_ < size_) {
			throw Exception();
		}
		return capacity_;
	}


	//връща препратка към първия елемент на вектора
	int& front() {
		if(!empty()) {
			return buffer_[0];
		}
		throw Exception();
	}

	//връща константна препратка към първия елемент на вектора
	const int& front() const{
		if(!empty()) {
			return buffer_[0];
		}
		throw Exception();
	}

	//връща препратка към последния елемент на вектора
	int& back() {
		if(!empty()) {
			return buffer_[size_ - 1];
		}
		throw Exception();
	}

	//връща константна препратка към последния елемент на вектора
	const int& back() const{
		if(!empty()) {
			return buffer_[size_ - 1];
		}
		throw Exception();
	}

	//добавя нов елемент след последния елемент на вектора
	void push_back(const int& value) {
		if(size_ == capacity_) {
			capacity_ = capacity_ * 2;
			int* temp = buffer_;
			buffer_ = new int[capacity_];

			for(int i = 1; i <= size_; i++) {
				buffer_[i] = temp[i];
			}
			delete [] temp;		
		}
		buffer_[size_++] = value;
	}

	//изтрива последния елемент на вектора
	void pop_back() {
		if(!empty()) {
			size_--;
		}
		throw Exception();
	}

	//копиращ конструктор
	Vector(const Vector& other)
	: capacity_(other.capacity_), size_(other.size_), buffer_(new int[other.capacity_]) {
		for(int i = 0; i < size_; i++) {
			buffer_[i] = other.buffer_[i];
		}
	}
	
	//оператор за присвояване
	Vector& operator=(const Vector& other) {
		if(this != &other) {
			delete [] buffer_;
			size_ = other.size_;
			capacity_ = other.capacity_;
			buffer_ = new int[capacity_];

			for(int i = 0; i < size_; i++) {
				buffer_[i] = other.buffer_[i];
			}
		}
		return *this;
	}


	//-----------------------------------------------------------------------------

	class iterator {
		friend class Vector;
		int * present_;
		
		iterator(int* present)
		: present_(present) {}
	public:
	
		iterator& operator++() {
			present_ = present_ + 1;
			return *this;
		}

		iterator operator++(int) {
			iterator previous(present_);
			present_ = present_ + 1;
			return previous;
		}

		bool operator==(const iterator& other) const {
			return present_ == other.present_;
		}

		bool operator!=(const iterator& other) const {
			return !present_ == (other);
		}

		const int& operator*() {
			return *present_;
		}	
	};

	iterator begin() {
		return iterator(&front());
	}
	
	iterator end() {
		return iterator(&buffer_[size_]);
	}


	//---------------------------------------------------------------------------------

	class const_iterator {
		friend class Vector;
		const int* present_;
		
		const_iterator(const int* present)
		: present_(present) {}
	public:
	
		const_iterator& operator++() {
			present_ = present_ + 1;
			return *this;
		}

		const_iterator operator++(int) {
			const_iterator previous(present_);
			present_ = present_ + 1;
			return previous;
		}

		bool operator==(const const_iterator& other) const {
			return present_ == other.present_;
		}

		bool operator!=(const const_iterator& other) const {
			return !present_ == (other);
		}

		const int& operator*() {
			return *present_;
		}	
	};

	const_iterator begin() const {
		return const_iterator(&front());
	}

	const_iterator end() const {
		return const_iterator(&buffer_[size_]);
	}

	//------------------------------------------------------------------------------

	class reverse_iterator {
		friend class Vector;
		int* present_;

		reverse_iterator(int* present)
		: present_(present) {}

	public:
		reverse_iterator& operator++() {
			present_ = present_ + 1;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator previous(present_);
			present_ = present_ + 1;
			return previous;
		}

		bool operator==(const reverse_iterator& other) const {
			return present_ == other.present_;
		}

		bool operator!=(const reverse_iterator& other) const {
			return !present_ == (other);
		}

		const int& operator*() {
			return *present_;
		}	
	};
	
	reverse_iterator rbegin() {
		return reverse_iterator(&buffer_[size_]);
	}
	
	reverse_iterator rend() {
		return reverse_iterator(&front());
	}

	//-------------------------------------------------------------------------

	class const_reverse_iterator {
		friend class Vector;
		const int* present_;

		const_reverse_iterator(const int* present)
		: present_(present) {}

	public:
		const_reverse_iterator& operator++() {
			present_ = present_ + 1;
			return *this;
		}

		const_reverse_iterator operator++(int) {
			const_reverse_iterator previous(present_);
			present_ = present_ + 1;
			return previous;
		}

		bool operator==(const const_reverse_iterator& other) const {
			return present_ == other.present_;
		}

		bool operator!=(const const_reverse_iterator& other) const {
			return !present_ == (other);
		}

		const int& operator*() {
			return *present_;
		}
	};

	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(&buffer_[size_]);
	}

	const_reverse_iterator rend() const {
		return const_reverse_iterator(&front());
	}

	//------------------------------------------------------------------
	
};

int main() {

	return 0;
}










