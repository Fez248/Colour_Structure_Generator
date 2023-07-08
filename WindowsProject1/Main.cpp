#include "Main.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "Cluster", wxPoint(30, 30), wxSize(800, 600))
{
	//Find Colors
	cdata = new wxColourDatabase();
	wxColour dark_grey = cdata->Find("DARK GREY");
	wxColour wheat = cdata->Find("WHEAT");

	SetOwnBackgroundColour(dark_grey);
	set_main_sizer(10);
	SetMinSize(wxSize(600, 300));
}

Main::~Main()
{
	delete(cdata);
}

void Main::set_main_sizer(const int margin)
{
	fl = new wxGridBagSizer(margin, margin);
	set_elements();
	this->SetSizerAndFit(fl);
}

void Main::set_elements()
{
	int size = elements.size();
	
	for (int i = 0; i < size; ++i)
	{
		wxGBPosition aux = elements[i].first;
		if (aux != wxGBPosition(0, 4)) 
		{
			wxPanel* paux = new wxPanel(this, wxID_ANY, wxDefaultPosition, fl->GetEmptyCellSize());

			if (aux == wxGBPosition(3, 0) or aux == wxGBPosition(4, 1))
			{
				paux->SetOwnBackgroundColour(wxColour(155, 155, 55));
			}
			else
			{
				paux->SetOwnBackgroundColour(wxColour(100, 100, 200));
			}

			fl->Add(paux, aux, elements[i].second, wxEXPAND);
		}
		else 
		{

		}
	}
}

/*
void Main::set_main_sizer(const int margin, wxGridBagSizer* fl, std::vector<std::pair<wxGBPosition, wxGBSpan>>& elements)
{
	fl = new wxGridBagSizer(margin, margin);
	set_elements(fl, elements);
	this->SetSizerAndFit(fl);
}

void Main::OnButton1(wxCommandEvent& event)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 255);
	int value1 = distribution(generator);
	int value2 = distribution(generator);
	int value3 = distribution(generator);

	int n = elements.size();
	for (int h = 0; h < n; ++h) 
	{
		wxGBPosition aux_pos = elements[h].first;
		wxGBSizerItem* aux = fl->FindItemAtPosition(aux_pos);
	}
}

void Main::set_elements(wxGridBagSizer* fl, std::vector<std::pair<wxGBPosition, wxGBSpan>>& elements)
{

	int number = elements.size();
	for (int i = 0; i < number; ++i) 
	{
		wxGBPosition aux = elements[i].first;
		
		if (aux != wxGBPosition(0, 4))
		{
			wxPanel* pls = new wxPanel(this, wxID_ANY, wxDefaultPosition, fl->GetEmptyCellSize());

			if (aux == wxGBPosition(3, 0) or aux == wxGBPosition(4, 1))
			{
				pls->SetOwnBackgroundColour(wxColour(155, 155, 55));
			}
			else
			{
				pls->SetOwnBackgroundColour(wxColour(100, 100, 200));
			}

			fl->Add(pls, elements[i].first, elements[i].second, wxEXPAND);
		}
		else 
		{
			wxButton* bt = new wxButton(this, wxID_ANY, "New color way", wxDefaultPosition, fl->GetEmptyCellSize(), wxBORDER_NONE);
			
			wxFont button_font = bt->GetFont();
			button_font.SetPointSize(20);
			button_font.SetFamily(wxFONTFAMILY_ROMAN);
			
			bt->SetFont(button_font);
			bt->SetOwnBackgroundColour(wxColour(155, 155, 55));

			Bind(wxEVT_BUTTON, &Main::OnButton1, this);
			fl->Add(bt, elements[i].first, elements[i].second, wxEXPAND);
		}
	}


	for (int j = 0; j < 8; ++j) fl->AddGrowableCol(j, 1);
	for (int h = 0; h < 6; ++h) fl->AddGrowableRow(h, 1);
}
*/