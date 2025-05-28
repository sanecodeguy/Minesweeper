#pragma once
#include<iostream>
#include<sstream>
#include<SFML/Graphics.hpp>
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
class Textbox
{
public:
	Textbox(int size, sf::Color color, bool sel)
	{
		textbox.setCharacterSize(size);
		textbox.setFillColor(color);
		is_selected = sel;
		if (sel)
		{
			textbox.setString("_");
		}
		else textbox.setString("");
	}
	void typedon(sf::Event i)
	{
		if (is_selected)
		{
			int chartyped = i.text.unicode;
			if (chartyped < 128)
			{
				if (haslimit)
				{
					if (text.str().length() <= limit)
					{
						input(chartyped);
					}
					else if (text.str().length() > limit && chartyped == DELETE_KEY)
					{
						deletelastchar();
					}
				}
				else input(chartyped);
			}
		}
	}
	void setfont(sf::Font& textfont)
	{
		textbox.setFont(textfont);
	}
	void setposition(sf::Vector2f pos)
	{
		textbox.setPosition(pos);
	}
	void setlimit(bool ToF)
	{
		haslimit = ToF;
	}
	void setlimit(bool ToF, int lim)
	{
		haslimit = ToF;
		limit = lim;
	}
	void setselected(bool sel)
	{
		is_selected = sel;
		if (!sel)
		{
			std::string t = text.str();
			std::string newt = "";
			for (int i = 0; i < t.length() - 1; i++)
			{
				newt += t[i];
			}
			textbox.setString(newt);
		}
	}
	std::string gettext()
	{
		return text.str();
	}
	void drawto(sf::RenderWindow& window)
	{
		window.draw(textbox);
	}
private:
	sf::Text textbox;
	std::ostringstream text;
	bool is_selected = false;
	bool haslimit = false;
	int limit;
	void deletelastchar()
	{
		std::string t = text.str();
		std::string newt = "";
		for (int i = 0; i < t.length() - 1; i++)
		{
			newt += t[i];
		}
		text.str("");
		text << newt;
		textbox.setString(text.str());
	}
	void input(int chartyped)
	{
		if (chartyped != DELETE_KEY && chartyped != ENTER_KEY && chartyped != ESCAPE_KEY)
		{
			text << static_cast<char>(chartyped);
		}
		else if (chartyped == DELETE_KEY)
		{
			if (text.str().length() >0)
			{
				deletelastchar();
			}
		}
		textbox.setString(text.str() + "_");
	}
};
