#include "Header_class.h"
#include "LList.h"
#include <iostream>

class matrix {
private:
	LList<Header>* column;
	LList<Header>* row;
public:
	matrix() {
		column = new LList<Header>();
		row = new LList<Header>();
	}
	~matrix() {
		delete column;
		delete row;
	}

	void insert(int i, int j, int val) {
		if (val == 0) { return; }
		Elem* e = new Elem(i, j, val);
		if (find(i, j) == NULL) {
			inserthelp('c', column, j, e);
			inserthelp('r', row, i, e);
		}
	}

	void transpose() {
		for (int i = 0; i < row->length(); i++) {
			row->getValue().transpose();
			row->next();
		}
		LList<Header>* temp = column;
		column = row;
		row = temp;
	}

	void add(matrix* m) {
		LList<Header>* row = m->r();
		Elem* temp;
		for (int i = 0; i < row->length(); i++) {
			temp = row->getValue().header();
			while (temp != NULL) {
				Elem* ptr = find(temp->row(), temp->column());
				if (ptr == NULL) {
					insert(temp->column(), temp->row(), temp->data());
				}
				else {
					ptr->setData(ptr->data() + temp->data());
				}
				temp = temp->right;
			}
			row->next();
		}
	}

	matrix* mul(matrix* m) {
		LList<Header>* col = m->c();
		matrix* product = new matrix();
		int sum = 0;
		Header* c = &col->getValue();
		Header r = row->getValue();
		for (int i = 0; i < row->length(); i++) {
			r = row->getValue();
			col->moveToStart();
			for (int j = 0; j < col->length(); j++) {
				c = &col->getValue();
				product->insert(r.index(), c->index(), r.mul(c));
				col->next();
			}
			row->next();	
		}
		return product;
	}

	Elem* find(int x, int y) {
		Header* col = NULL;
		column->moveToStart();
		for (int i = 0; i < column->length(); i++) {
			if (index(column) == y) {
				col = &column->getValue();
				break;
			}
			column->next();
		}
		column->moveToStart();
		if (col == NULL) { return NULL; }
		Elem* node = col->header();
		for (int j = 0; j < row->length(); j++) {
			if (node->row() == x) {
				row->moveToStart();
				return node;
			}
			node = node->down;
			if (node == NULL) { return NULL; }
		}
		row->moveToStart();
		return NULL;
	}

	 inline LList<Header>* c() { return column; }

	 inline LList<Header>* r() { return row; }

	void inserthelp(char c,  LList<Header>* headers, int elemIndex, Elem* n) {
		headers->moveToStart();
		for (int i = 0; i <= headers->length(); i++) {
			if (headers->length() == 0 || i == headers->length() || index(headers) > elemIndex) {
				Header head(c, elemIndex, n);
				headers->insert(head);
				headers->moveToStart();
				break;
			}
			else if (index(headers) == elemIndex) {
				headers->getValue().add(n);
				headers->moveToStart();
				break;
			}
			headers->next();
		}

		return;
	}

	void del(int i, int j) {
		Elem* e = find(i, j);
		if (e == NULL) { return; }
		Header* header = NULL;
		bool cRemove = false, rRemove = false;
		column->moveToStart();
		for (int a = 0; a < column->length(); a++) {
			if (index(column) == j) {
				header = &column->getValue();
				break;
			}
			column->next();
		}
		if (e->up == NULL && e->down == NULL) {
			cRemove = true;
		}
		else if (e->up == NULL) {
			e->down->up = NULL;
			header->setHead(e->down);
		}
		else if (e->down == NULL) {
			e->up->down = NULL;
		}
		else {
			e->up->down = e->down;
			e->down->up = e->up;
		}
		//Delete for Rows
		row->moveToStart();
		for (int a = 0; a < row->length(); a++) {
			if (index(row) == i) {
				header = &row->getValue();
				break;
			}
			row->next();
		}
		if (e->left == NULL && e->right == NULL) {
			rRemove = true;
		}
		else if (e->left == NULL) {
			e->right->left = NULL;
			header->setHead(e->right);
		}
		else if (e->right == NULL) {
			e->left->right = NULL;
		}
		else {
			e->left->right = e->right;
			e->right->left = e->left;
		}
		if (cRemove) { column->remove(); }
		if (rRemove) { row->remove(); }
		if (!cRemove && !rRemove) {
			delete e;
		}
		return;
	}

	inline int index(LList<Header>*l) {
		return l->getValue().index();
	}

	void print() {
		std::cout << "Columns--------------" << std::endl;
		column->print();
		std::cout << "Rows-----------------" << std::endl;
		row->print();
	}
};