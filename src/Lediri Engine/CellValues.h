#ifndef _CELLVALUES
#define _CELLVALUES

#include "Vect.h"
struct CellValues
{
public:
	CellValues() = default;
	CellValues(const CellValues&) = delete;
	CellValues& operator=(const CellValues&) = delete;
	~CellValues() = default;

	Vect min;
	Vect max;
};
#endif