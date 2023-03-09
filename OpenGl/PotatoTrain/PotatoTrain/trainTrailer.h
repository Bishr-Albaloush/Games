#include <cmath>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>
#include "Model_3DS.h"
#include "3DTexture.h"


class trainTrailer
{
	public:
		Model_3DS *Bag;
		GLTexture bag;
		float x,y,z,width,height,depth;
		bool isOpen;
		float transparency;
		int textureIndex;
		int textureIndex1;
		int textureIndex2;
		int textureIndex3;
		int textureIndex4;
		int textureIndex5;
		float spaceBetween;
		trainTrailer();
		trainTrailer(float a,float b,float c,int d,int d1,int d2,int d3,int d4,int d5,float width,float height,float depth,bool isOpen);
		void drawFirstTrailer();
		void drawLastTrailer();
		void drawTrailer(int stuff);
		void drawWheel(float x,float y,float z,int frontOrBack,int rightOrLeft);
		void drawStand(float x,float y,float z,float w,float d,float h);
		void drawChair(float x,float y,float z,int frontOrBack);
		void drawSeatsTrailer();
		void drawTable(float x,float y,float z);
		void drawResturantTrailer();
		//void drawBag(float x,float y,float z);
};
