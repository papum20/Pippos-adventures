#ifndef HEALTH_POTION_HPP
#define HEALTH_POTION_HPP


#include "../powerup.hpp"
#define HEALTH_GAINED 10


class HealthPotion : public PowerUp {
	private:
		int healthGained;
	public:
		HealthPotion();

		void ChangeStats();
};





#endif