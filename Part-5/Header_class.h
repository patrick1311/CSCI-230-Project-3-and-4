#include "m_elem.h"

class Header {

private:
	char c;
	int pos;
	int len;
	Elem* head;

public:
	Header() { head = NULL; }
	Header(char a, int p, Elem* h) { head = h; c = a; pos = p; len = 1; }
	~Header() {}
	Elem* header(){return head;}
	inline char type() {return c;}
	inline int index(){return pos;}
	inline void setHead(Elem * h) {
		head = h;
	}

	void print() {
		Elem* temp = head;
		while (temp != NULL) {
			temp->print();
			if (c == 'c') {
				temp = temp->down;
			}
			else {
				temp = temp->right;
			}
		}
		std::cout << std::endl;
	}

	inline void add(Elem* e) {
		head = head->add(c, e);
		len++;
	}

	int length() { return len; }

	int mul(Header* h) {
		if (h->type() == 'r') { return NULL; }
		int sum = 0;
		Elem* temp = header();
		Elem* temp2 = h->header();
		for (int i = 0; i < h->length(); i++) {
			temp = header();
			for (int j = 0; j < length(); j++) {
				if (temp2->row() == temp->column()) {
					sum += temp2->data()*temp->data();
					break;
				}
				temp = temp->right;
			}
			temp2 = temp2->down;
		}
		return sum;
	}

	void transpose() {
		Elem* temp = head;
		while (temp != NULL) {
			temp->transpose();
			if (c == 'c') {
				temp = temp->right;
			}
			else {
				temp = temp->down;
			}
		}
		if (c == 'c') { c = 'r'; }
		else { c = 'c'; }
	}
};
