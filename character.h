#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class character
{
	public:
		CircleShape characterShape;
		void display(RenderWindow &window);
		Vector2f position();
		character();
	private:
		void left();
		void right();
		void up();
		void down();
		void steering();
};