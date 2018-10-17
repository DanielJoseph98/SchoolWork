#ifndef VERTEXTYPE_H
#define VERTEXTYPE_H


#include <iostream>
using namespace std;
	enum  MARK { DEFAULT, VISITED, QUEUED };
class VertexType{

  
    public:



	bool operator==(const VertexType &other) const {
		return(value==other.value);
      	}
	bool operator!=(const VertexType &other) const {
		return!(value==other.value);
      	}
	void operator =(const VertexType &other)
	{
		this->value = other.value;
		this->mark = other.mark;
	}

	VertexType()
	{
		VertexType("");
		mark = DEFAULT;
	}
	VertexType(string value)
	{
		this->value = value;
		mark = DEFAULT;
		queued = false;
	}
		
	void setMark(MARK m)
	{
		mark = m;
		queued= true;
	}

	void printValue()
	{
		cout << value;
	}

	bool isDefault()
	{
		return (!queued);
	}
	void Queue()
	{
		queued = true;
	}

	void printMark()
	{
		switch(mark){
			case DEFAULT: cout << "default";
				      break;
			case VISITED: cout << "visited";
				      break;
			case QUEUED: cout << "queued";
				     break;
			default:cout <<  "this is broken";
		}

	}

	MARK getMark()
	{
		return mark;
	}

    private:
	string value;
	MARK mark;
	bool queued;
};

#endif
