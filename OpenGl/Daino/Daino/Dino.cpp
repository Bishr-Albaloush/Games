#include "Dino.h"
#include <windows.h>
#include <gl\gl.h>
#include <cmath>

void Dino::DrawDino(Point center, float width, float length, Point cord1, Point cord2, Point cord3, Point cord4)
{
	glBegin(GL_QUADS);

	glTexCoord2d(cord1.x,cord1.y);
	glVertex3d(center.x - width/2,center.y - length/2,0);
 
	glTexCoord2d(cord2.x,cord2.y);
	glVertex3d(center.x + width/2,center.y - length/2,0);
 
	glTexCoord2d(cord3.x,cord3.y);
	glVertex3d(center.x + width/2,center.y + length/2,0);
 
	glTexCoord2d(cord4.x,cord4.y);
	glVertex3d(center.x - width/2,center.y + length/2,0);
 
	glEnd();
}