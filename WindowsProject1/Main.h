#pragma once
#include <wx/wx.h>
#include <wx/gbsizer.h>
#include <vector>
#include <random>
#include <list>

class Main : public wxFrame
{
public:
	Main();
	~Main();

private:

	wxColourDatabase* cdata = nullptr;
	wxGridBagSizer* fl = nullptr;

	std::list<wxPanel*> panel_list;
	std::list<wxButton*> button_list;

	std::vector<std::pair<wxGBPosition, wxGBSpan>> elements =
	{
		{{0, 0},{3, 4}},
		{{0, 4},{6, 4}}, //este
		{{3, 0},{1, 2}}, //este
		{{3, 2},{1, 2}},
		{{4, 0},{1, 1}},
		{{4, 1},{1, 3}}, //este
		{{5, 0},{1, 4}}
	};



	void set_main_sizer(const int margin);

	void set_elements();

	void OnButton1(wxCommandEvent& event);
};

