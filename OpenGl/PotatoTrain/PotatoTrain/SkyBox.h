#include <cmath>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>
#include "Model_3DS.h"
#include "3DTexture.h"



class SkyBox
{
public:
	Model_3DS *tree[6];
	GLTexture Bark, Leaf;
	float size;
	int sky,ground,face;
	float start,end,curZ,movment;
	float start1,end1,curZ1;
	bool isMoving;
	SkyBox();
    SkyBox(float size,int sky,int ground,int face);
	void drawTree();
    void draw();
	void stopStart();
	void moveground();

};
