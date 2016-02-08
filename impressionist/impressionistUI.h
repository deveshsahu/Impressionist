//
// impressionistUI.h
//
// The header file for the UI part
//

#ifndef ImpressionistUI_h
#define ImpressionistUI_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Chooser.H>		// FLTK file chooser
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Round_Button.H>

#include "impressionist.h"
#include "originalView.h"
#include "paintView.h"

#include "impBrush.h"

const int FLT_WIDTH = 5;
const int FLT_HEIGHT = 5;
enum
{
	MEAN_FILTER = 7,
	WT_MEAN_FILTER = 8,
	NUM_FILTER_TYPE
};


class ImpressionistUI {
public:
	ImpressionistUI();
	~ImpressionistUI();

	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;
								
	PaintView*			m_paintView;
	OriginalView*		m_origView;

// for brush dialog
	Fl_Window*			m_brushDialog;
	Fl_Choice*			m_BrushTypeChoice;

	Fl_Slider*			m_BrushSizeSlider;
	Fl_Slider*			m_BrushThicknessSlider;
	Fl_Slider*			m_BrushDensitySlider;
	Fl_Slider*			m_BrushAlphaSlider;
	Fl_Slider*			m_BrushStrokeAngleSlider;
	Fl_Button*          m_ClearCanvasButton;
	Fl_Round_Button*	    	m_strokeDir1;
	Fl_Round_Button*	    	m_strokeDir2;
	Fl_Round_Button*	    	m_strokeDir3;

// for filter dialog
	Fl_Window*			m_filterDialog;
	Fl_Choice*			m_filterTypeChoice;
	
	Fl_Button*		m_PreviewFilterButton;
	Fl_Button*		m_ApplyFilterButton;	
	Fl_Button*		m_CancelFilterButton;	

	// Member functions
	void				setDocument(ImpressionistDoc* doc);
	ImpressionistDoc*	getDocument();

	void				show();
	void				resize_windows(int w, int h);

	// Interface to get attribute

	int					getSize();
	void				setSize(int size);
	
	int					getThickness();
	void				setThickness(int thickness);
	
	int					getDensity();
	void				setDensity(int density);
	
	int					getAlpha();
	void				setAlpha(int density);
	
	double					getStrokeAngle();
	void				setStrokeAngle(double angle);

	// Callbacks for the image filter dialogue (different from
	// the other callbacks because they aren't static)
	void				initFltDesignUI(void);
	void				updateFilter(void);

	void				cancelFilter(void);
	void				applyFilter(void);
	void				previewFilter(void);


private:
	ImpressionistDoc*	m_pDoc;		// pointer to document to communicate with the document

	// All attributes here
	int		m_nSize;
	int		m_nThickness;
	int		m_nDensity;
	int		m_nAlpha;
	double		m_nAngle;
	// These attributes are set by the filter kernel UI
	double fltKernel[FLT_WIDTH*FLT_HEIGHT];		//the kernel of the image filter
	double scale,offset;						//the divisor and offset parameter, 
												//applied after convolving to transform 
												//the filtered image into the range [0,255]


	// Static class members
	static Fl_Menu_Item		menuitems[];
	static Fl_Menu_Item		brushTypeMenu[NUM_BRUSH_TYPE+1];
	static Fl_Menu_Item		filterTypeMenu[NUM_FILTER_TYPE+1];
	//static Fl_Menu_Item 		strokeChoiceMenu[];

	static ImpressionistUI*	whoami(Fl_Menu_* o);

	// All callbacks here.  Callbacks are declared 
	// static
	static void	cb_load_image(Fl_Menu_* o, void* v);
	static void	cb_save_image(Fl_Menu_* o, void* v);
	static void	cb_brushes(Fl_Menu_* o, void* v);
	static void	cb_filter_kernel(Fl_Menu_* o, void* v);
	static void	cb_clear_canvas(Fl_Menu_* o, void* v);
	static void	cb_exit(Fl_Menu_* o, void* v);
	static void	cb_about(Fl_Menu_* o, void* v);
	static void	cb_brushChoice(Fl_Widget* o, void* v);
	static void	cb_clear_canvas_button(Fl_Widget* o, void* v);
	static void	cb_sizeSlides(Fl_Widget* o, void* v);
	static void	cb_thicknessSlides(Fl_Widget* o, void* v);
	static void	cb_densitySlides(Fl_Widget* o, void* v);
	static void	cb_alphaSlides(Fl_Widget* o, void* v);
	static void	cb_strokeAngle(Fl_Widget* o, void* v);
	//static void	cb_stroke(Fl_Widget* o, void* v);
	static void	cb_strokeDir1(Fl_Widget* o, void* v);
	static void	cb_strokeDir2(Fl_Widget* o, void* v);
	static void	cb_strokeDir3(Fl_Widget* o, void* v);
	
	static void	cb_apply_filter_button(Fl_Widget* o, void* v);
	static void	cb_preview_filter_button(Fl_Widget* o, void* v);
	static void	cb_cancel_filter_button(Fl_Widget* o, void* v);
	static void	cb_filterChoice(Fl_Widget* o, void* v);
	
	static void	cb_filter(Fl_Menu_* o, void* v);
	
	static void	cb_setFilterMean(Fl_Widget* o, void* v);

	
};

#endif

