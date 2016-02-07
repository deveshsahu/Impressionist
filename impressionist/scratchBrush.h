//
// scratchBrush.h
//
// The header file for Scratch Brush. 
//

#ifndef SCRATCHBRUSH_H
#define SCRATCHBRUSH_H

#include "impBrush.h"

class ScratchBrush : public ImpBrush
{
public:
	ScratchBrush( ImpressionistDoc* pDoc = NULL, const char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );
};

#endif
