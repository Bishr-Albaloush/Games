#include <cmath>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>


class railWay
{
	public:
		float x,y,z;
		int railWayImage;
		float width,len;
		railWay(float x,float y,float z,int railWayImage);
		void drawRailWay();
};
