//
// cprayBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include<cmath>
#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "csprayBrush.h"

extern float frand();

CsprayBrush::CsprayBrush( ImpressionistDoc* pDoc, const char* name ) :
	ImpBrush(pDoc,name)
{
}

void CsprayBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();



	//glPointSize( (float)size );
	//glPointSize( (float)size );

	BrushMove( source, target );
}

void oneCircle(double x, double y, float size){
	glBegin( GL_POLYGON );
		for (int i = 0;i<360;i++)
			glVertex2d( x +size*cos(6.28*i/360) , y+size*sin(6.28*i/360));

	glEnd();
}


void CsprayBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "CsprayBrush::BrushMove  document is NULL\n" );
		return;
	}
	
	int size = pDoc->getSize();
	int density = pDoc->getDensity();
	int alpha = pDoc->getAlpha();
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	SetColor( source , alpha);
	for (int i = 0;i<density;i++){
			float r = rand() %10 ;
			r = r*size/10;
			oneCircle(target.x+r*cos(6.28*i/density) , target.y+r*sin(6.28*i/density), rand()%3);
		}

}

void CsprayBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}

