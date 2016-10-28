#include "Component.h"

class PlayerComponent : public Component
{
public:
	PlayerComponent();

	void move();

	void update();
private:
	int aimSpeed;
};

