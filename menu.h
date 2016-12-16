#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class menu
{
	private:
		ContextSettings settings;
		Color background;
		Text tittle;
		Text play;
		Text options;
		Text autor;
		Text exit;
		Font retro;
		RectangleShape line;
		bool mouseontext(RenderWindow &window, Text &text);
		int choice;
	public:
		menu();
		int menudisplay(RenderWindow &window);
		bool choiced;
};