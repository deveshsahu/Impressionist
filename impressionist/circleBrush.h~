//
// sprayBrush.h
//
// The header file for Sprays Brush. 
//

#ifndef SPRAYBRUSH_H
#define SPRAYBRUSH_H

#include "impBrush.h"

class SprayBrush : public ImpBrush
{
public:
	SprayBrush( ImpressionistDoc* pDoc = NULL, const char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );
};

#endif
