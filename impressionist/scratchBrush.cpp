//
// lineBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include <math.h>

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "lineBrush.h"
#include "scratchBrush.h"

#define PI 3.14159
extern float frand();

ScratchBrush::ScratchBrush( ImpressionistDoc* pDoc, const char* name ) :
	ImpBrush(pDoc,name)
{
}

void ScratchBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int width = pDoc->getThickness();


	//glPointSize( (float)size );
	glLineWidth( (float)width );

	BrushMove( source, target );
}

void ScratchBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "ScratchBrush::BrushMove  document is NULL\n" );
		return;
	}
	
	int size = pDoc->getSize();
	
	int alpha = pDoc->getAlpha();
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	SetColor( source , alpha );
	
	double angle = pDoc->getStrokeAngle();
	printf("Unknown event!! %f \n",angle);
	glBegin( GL_LINES );
		
		glVertex2d( target.x, target.y );
		glVertex2d( target.x + cos(angle)*size, target.y + sin(angle)*size );
		
		glVertex2d( target.x - sin(angle)*size/2, target.y + cos(angle)*size/2);
		glVertex2d( target.x - sin(angle)*size/2 + cos(angle)*size,
			    target.y + cos(angle)*size/2 + sin(angle)*size );	
		
		glVertex2d( target.x + sin(angle)*size/2, target.y - cos(angle)*size/2);
		glVertex2d( target.x + sin(angle)*size/2 + cos(angle)*size, 
			    target.y - cos(angle)*size/2 + sin(angle)*size );

	glEnd();
}

void ScratchBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}

