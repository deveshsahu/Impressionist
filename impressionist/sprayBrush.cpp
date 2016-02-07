//
// sprayBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "sprayBrush.h"

extern float frand();

SprayBrush::SprayBrush( ImpressionistDoc* pDoc, const char* name ) :
	ImpBrush(pDoc,name)
{
}

void SprayBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	glPointSize( 3 );
	

	BrushMove( source, target );
}

void SprayBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "SprayBrush::BrushMove  document is NULL\n" );
		return;
	}
	
	int size = pDoc->getSize();
	int density = pDoc->getDensity();
	int alpha = pDoc->getAlpha();
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	for (int i = 0; i<density; i++)
		{
			glPointSize( rand()%5+1 );
			glBegin( GL_POINTS );
			SetColor( source , alpha );
			glVertex2d( target.x - size/2 + rand()%size, target.y -size/2 + rand()%size);
			glEnd();
		}
}

void SprayBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}

