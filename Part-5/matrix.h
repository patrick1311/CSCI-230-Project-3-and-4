#include "Header_class.h"
#include "LList.h"
#include <iostream>

class matrix
{
private:
	LList<Header>* column;
	LList<Header>* row;
public:
	matrix()
	{
		column = new LList<Header>();
		row = new LList<Header>();
	}
	void insert(int i, int j, int val)
	{
		Elem* e = new Elem(i,j,val);
		inserthelp(e);	
	}
	LList<Header>* c() { return column; }
	LList<Header>* r() { return row; }
	void inserthelp(Elem* n)
	{
		
		for( int i = 0; i <=column->length(); i++)
		{
			if (column->length() == 0 || i == column->length()|| column->getValue().index() > n->column())
			{
				 Header head('c', n->column(), n);
				column->insert(head);
				column->moveToStart();
				break;
			}
			else if (column->getValue().index() == n->column())
			{
				column->getValue().add(n);
				column->moveToStart();
				break;
			}
			column->next();
		}

		for (int j = 0; j <=row->length(); j++)
		{
			if (row->length() == 0 || j == column->length() || row->getValue().index() > n->row())
			{
				Header head('r', n->row(), n);
				row->insert(head);
				row->moveToStart();
				break;
			}
			else if (row->getValue().index() == n->row())
			{
				row->getValue().add(n);
				row->moveToStart();
				break;
			}
			row->next();
		}
		return;
	}

	void print()
	{
		column->print();
		std::cout << std::endl;
		row->print();
	}
};