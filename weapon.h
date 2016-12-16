#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class weapon
{
	private:
		RectangleShape weaponShape;
		RectangleShape weaponBarrel;
		RectangleShape weaponChamber;
		RectangleShape weaponBody;
		int FireCountMove;
		bool FireFinished;
		bool MousePressed;
		bool autofire;
		bool firebutton;
		Text mode;
		Text type;
		Font font;
	public:
		weapon();
		void display(RenderWindow &window, Vector2f user);
		void fireanimation();
		void fireactionmouse();
};