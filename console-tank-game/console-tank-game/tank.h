#pragma once
class tank
{
	int ap;
	int shot_cost = 2;

	int location_x;
	int location_y;

	void move();

	void shot();

	bool can_move();
};