#include "railWay.h"


railWay::railWay(float x,float y,float z,int railWayImage)
{
	this->x=x;
	this->y=y;
	this->z=z;
	this->railWayImage=railWayImage;
	width=26;
	len=20;
}


void railWay::drawRailWay()
{
	for(float i=-1*z;i<=z;i+=len)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, railWayImage);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(-width,y,i);
			glTexCoord2d(0, 1);
			glVertex3d(x+width,y,i);
			glTexCoord2d(1, 1);
			glVertex3d(x+width,y,i+len);
			glTexCoord2d(1, 0);
			glVertex3d(-width,y,i+len);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}
