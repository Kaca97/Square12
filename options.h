#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class options
{
	public:
		options();
		int display(RenderWindow &window);
		void check();
	private:
		Font retro;
		Text header;
		Text back;
		Text moveup;
		Text movedown;
		Text moveright;
		Text moveleft;
		Text test;
		ContextSettings settings;
		Color background;
		bool mouseontext(RenderWindow &window, Text &text);
};