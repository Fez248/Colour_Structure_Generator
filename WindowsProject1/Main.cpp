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
			wxPanel* paux = new wxPanel(this, i, wxDefaultPosition, fl->GetEmptyCellSize());

			if (aux == wxGBPosition(3, 0) or aux == wxGBPosition(4, 1))
			{
				paux->SetOwnBackgroundColour(wxColour(155, 155, 55));
			}
			else
			{
				paux->SetOwnBackgroundColour(wxColour(100, 100, 200));
			}

			fl->Add(paux, aux, elements[i].second, wxEXPAND);
			panel_list.insert(panel_list.end(), paux);
		}
		else 
		{
			wxButton* baux = new wxButton(this, i, "New Color Structure", wxDefaultPosition, fl->GetEmptyCellSize(), wxBORDER_NONE);
			baux->SetOwnBackgroundColour(wxColour(155, 155, 55));

			wxFont button_font = baux->GetFont();
			button_font.SetPointSize(20);
			button_font.SetFamily(wxFONTFAMILY_ROMAN);

			baux->SetFont(button_font);

			Bind(wxEVT_BUTTON, &Main::OnButton1, this);

			fl->Add(baux, aux, elements[i].second, wxEXPAND);
			button_list.insert(button_list.end(), baux);
		}
	}

	for (int j = 0; j < 8; ++j) fl->AddGrowableCol(j, 1);
	for (int h = 0; h < 6; ++h) fl->AddGrowableRow(h, 1);
}

void Main::OnButton1(wxCommandEvent& event)
{
	srand((unsigned)time(NULL));
	int value1, value2, value3;

	value1 = rand() % 256;
	value2 = rand() % 256;
	value3 = rand() % 256;

	wxButton* auxb = *button_list.begin();
	auxb->SetOwnBackgroundColour(wxColour(255 - value1, 255 - value2, 255 - value3));

	std::list<wxPanel*>::iterator ite = panel_list.end();
	for (std::list<wxPanel*>::iterator it = panel_list.begin(); it != ite; ++it)
	{
		wxPanel* auxp = *it;
		int id = auxp->GetId();

		if (id == 2 or id == 5) auxp->SetOwnBackgroundColour(wxColour(255 - value1, 255 - value2, 255 - value3));
		else auxp->SetOwnBackgroundColour(wxColour(value1, value2, value3));

		auxp->Refresh();
	}
}