//
// CsprayBrush.h
//
// The header file for Csprays Brush. 
//

#ifndef CSPRAYBRUSH_H
#define CSPRAYBRUSH_H

#include "impBrush.h"

class CsprayBrush : public ImpBrush
{
public:
	CsprayBrush( ImpressionistDoc* pDoc = NULL, const char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );
};

#endif
