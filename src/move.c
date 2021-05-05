#include <math.h>
#include "model.h"
#include "callbacks.h"
#include "move.h"

int movingWhichobjektum = 0;

void move_objektum(World* world) {
	
	if(movingWhichobjektum == 0) {
		if(abs((int)(camera.position.x - world->objektum1.position.x)) + abs((int)(camera.position.z - world->objektum1.position.z)) <
				abs((int)(camera.position.x - world->objektum2.position.x)) + abs((int)(camera.position.z - world->objektum2.position.z))) {
			movingWhichobjektum = 1;
			if(abs((int)(camera.position.x - world->objektum1.position.x)) + abs((int)(camera.position.z - world->objektum1.position.z)) <
					abs((int)(camera.position.x - world->objektum3.position.x)) + abs((int)(camera.position.z - world->objektum3.position.z))) {
				movingWhichobjektum = 1;
			} else {
				movingWhichobjektum = 3;
			}
		} else {
			movingWhichobjektum = 2;
			if(abs((int)(camera.position.x - world->objektum2.position.x)) + abs((int)(camera.position.z - world->objektum2.position.z)) <
					abs((int)(camera.position.x - world->objektum3.position.x)) + abs((int)(camera.position.z - world->objektum3.position.z))) {
				movingWhichobjektum = 2;
			} else {
				movingWhichobjektum = 3;
			}
		}
	}

	if(abs(camera.position.x) < 170 && abs(camera.position.z) < 170)
	{
		switch (movingWhichobjektum) {
			case 1:
				if (abs((int)(camera.position.x - world->objektum1.position.x)) < 50 && abs((int)(camera.position.z - world->objektum1.position.z)) < 50 && camera.position.y < 150)
				{
					world->objektum1.position.x = camera.position.x + 10;
					world->objektum1.position.z = camera.position.z + 10;

					world->objektum1.material_ambient[0] = camera.position.x / 200;
					world->objektum1.material_ambient[1] = camera.position.y / 200;
					world->objektum1.material_ambient[2] = camera.position.z / 200;
				}

				break;
			case 2:
				if (abs((int)(camera.position.x - world->objektum2.position.x)) < 50 && abs((int)(camera.position.z - world->objektum2.position.z)) < 50 && camera.position.y < 150)
				{
					world->objektum2.position.x = camera.position.x + 10;
					world->objektum2.position.z = camera.position.z + 10;

					world->objektum2.material_ambient[0] = camera.position.x / 200;
					world->objektum2.material_ambient[1] = camera.position.y / 200;
					world->objektum2.material_ambient[2] = camera.position.z / 200;
				}

				break;
			case 3:
				if (abs((int)(camera.position.x - world->objektum3.position.x)) < 50 && abs((int)(camera.position.z - world->objektum3.position.z)) < 50 && camera.position.y < 150)
				{
					world->objektum3.position.x = camera.position.x + 10;
					world->objektum3.position.z = camera.position.z + 10;

					world->objektum3.material_ambient[0] = camera.position.x / 200;
					world->objektum3.material_ambient[1] = camera.position.y / 200;
					world->objektum3.material_ambient[2] = camera.position.z / 200;
				}

				break;	
		}
	}
}
