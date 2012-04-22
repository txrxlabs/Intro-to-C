#include <stdio.h>

/*
 * Suppose you're writing a video game similar to space invaders
 * except suppose you have several different types of enemies.
 * There is some common data which you need to keep for all enemies
 * regardless of which kind they are, and then there is some data
 * that is particular to that kind of enemy.
 *
 * You can create a union to hole the type-specific data.
 *
 * A union is like a struct, except every member of the union
 * occupies the same memory.  The idea is, you normally only
 * use _one_ of the members at a time.
 *
 */

struct regular_enemy_data {
	int bullets_left;
}

struct bomber_enemy_data {
	int bombs_left;
	int shield_power;
	int laser_power;
}

struct tentacle_data {
	float tentacle_angle
	float tentacle_curl_factor;
};

struct squid_enemy_data {
	int number_of_tentacles;
	int gallons_of_ink;
	struct tentacle_data *tentacle[8];
};

union type_specific_data {
	/* All these structures occupy the same memory */
	/* You can only use one of them at a time. */
	struct regular_enemy_data regular;
	struct bomber_enemy_data bomber;
	struct squid_enemy_data squid;
}
	
struct enemy {
	int x, y;		/* position */
	int color;		/* color of the enemy */
	void (*move)(void);	/* pointer to function to move the enemy */
	void (*draw)(void);	/* pointer to function to draw the enemy */
	int enemy_type;
	union type_specific_data tsd;
};

/* now you have a type, 'struct enemy' which you can use for all of your
 * enemies.  The data which is specific to the various types of enemies
 * is stored in the type_specific_data union 'tsd.'
 *
 * Note also, you can assign different function pointers to the move and draw
 * methods depending on the enemy types, and these can refer to the type specific
 * data without reference to the enemy_type field, so long as you assingn those
 * pointers carefully.
 * 
 */

