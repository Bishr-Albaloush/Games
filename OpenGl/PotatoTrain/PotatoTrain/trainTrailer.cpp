#include "trainTrailer.h"

trainTrailer::trainTrailer(){}
trainTrailer::trainTrailer(float a,float b,float c,int d,int d1,int d2,int d3,int d4,int d5,float width,float height,float depth,bool isOpen)
{
	x=a;
	y=b;
	z=c;
	this->isOpen=isOpen;
	textureIndex=d;
	textureIndex1=d1;
	textureIndex2=d2;
	textureIndex3=d3;
	textureIndex4=d4;
	textureIndex5=d5;
	this->width=width;
	this->height=height;
	this->depth=depth;
	spaceBetween=15;
	transparency=0.4;
	/*bag.LoadBMP("bag.bmp");
	Bag= new Model_3DS ( );
	Bag->Load("bag.3ds");
	Bag->Materials[0].tex=bag;*/
}

//void trainTrailer::drawBag(float x,float y,float z)
//{
//	
//	/*Bag->pos.x=x;
//	Bag->pos.y=y;
//	Bag->pos.z=z;
//	Bag->Draw();
//	*/
//}

void trainTrailer::drawTable(float x,float y,float z)
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	float tableWidth=11,tableDepth=2*tableWidth,tableHeight=10;
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y+tableHeight,z);
			glTexCoord2d(1, 0);
			glVertex3d(x+tableWidth,y+tableHeight,z);
			glTexCoord2d(1, 1);
			glVertex3d(x+tableWidth,y+tableHeight,z+tableDepth);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+tableHeight,z+tableDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		drawStand(x+tableWidth/2,y,z+tableDepth/2,3,3,10);
		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
}
void trainTrailer::drawResturantTrailer()
{
	float chairWidth=12,chairDepth=-6,chairHeight=10,backDepth=-1;
	float curZ=z-chairDepth*2;
	drawChair(x,y,curZ,1);
	drawChair(x+(width*3/4-2),y,curZ,1);
	curZ-=-2;
	drawTable(x,y,curZ);
	drawTable(x+(width*3/4-2),y,curZ);
	curZ-=5*chairDepth+1;
	drawChair(x,y,curZ,-1);
	drawChair(x+(width*3/4-2),y,curZ,-1);
}


void trainTrailer::drawSeatsTrailer()
{
	float chairWidth=12,chairDepth=-6,chairHeight=10,backDepth=-1;
	float curZ=z-chairDepth*2;
	for(int i=0;i<4;i++)
	{
		drawChair(x,y,curZ,-1);
		drawChair(x+(3*width/4)-2,y,curZ,-1);
		curZ-=2*chairDepth;
	}
}

void trainTrailer::drawChair(float x,float y,float z,int frontOrBack)
{
	glColor4d(1,1,1,1);
	float chairWidth=12,chairDepth=-6,chairHeight=14,backDepth=-1;
	
	glPushMatrix();
	if(frontOrBack==1)
	{
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y,z+chairDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y,z+chairDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight,z+chairDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+chairWidth,y,z+chairDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y,z);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight/2+1,z);
			glTexCoord2d(0, 1);
			glVertex3d(x+chairWidth,y+chairHeight/2+1,z+chairDepth);
		glEnd();
		
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y,z+chairDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x,y,z);
			glTexCoord2d(1, 1);
			glVertex3d(x,y+chairHeight/2+1,z);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight/2+1,z+chairDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y,z-2);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y,z-2);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight/2,z-2);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight/2,z-2);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y+chairHeight,z+chairDepth-backDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth-backDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight,z+chairDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y+chairHeight/2,z+chairDepth-backDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x,y+chairHeight/2,z+chairDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x,y+chairHeight,z+chairDepth);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight,z+chairDepth-backDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+chairWidth,y+chairHeight/2,z+chairDepth-backDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y+chairHeight/2,z+chairDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth);
			glTexCoord2d(0, 1);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth-backDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex3);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y+chairHeight/2,z+chairDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y+chairHeight/2,z+chairDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight/2,z);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight/2,z);
		glEnd();

		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex3);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y+chairHeight/2,z+chairDepth-backDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y+chairHeight/2,z+chairDepth-backDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth-backDepth);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight,z+chairDepth-backDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex3);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y+chairHeight/2-2,z);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y+chairHeight/2-2,z);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight/2,z);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight/2,z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
		glPopMatrix();
		return ;
	}

	else if(frontOrBack==2)
	{
		
		glTranslated(460,0,432);
		glRotatef(-90,0,1,0);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y,z+chairDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y,z+chairDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight,z+chairDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+chairWidth,y,z+chairDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y,z);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight/2+1,z);
			glTexCoord2d(0, 1);
			glVertex3d(x+chairWidth,y+chairHeight/2+1,z+chairDepth);
		glEnd();
		
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y,z+chairDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x,y,z);
			glTexCoord2d(1, 1);
			glVertex3d(x,y+chairHeight/2+1,z);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight/2+1,z+chairDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y,z-2);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y,z-2);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight/2,z-2);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight/2,z-2);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y+chairHeight,z+chairDepth-backDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth-backDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight,z+chairDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y+chairHeight/2,z+chairDepth-backDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x,y+chairHeight/2,z+chairDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x,y+chairHeight,z+chairDepth);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight,z+chairDepth-backDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+chairWidth,y+chairHeight/2,z+chairDepth-backDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y+chairHeight/2,z+chairDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth);
			glTexCoord2d(0, 1);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth-backDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex3);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y+chairHeight/2,z+chairDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y+chairHeight/2,z+chairDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight/2,z);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight/2,z);
		glEnd();

		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex3);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y+chairHeight/2,z+chairDepth-backDepth);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y+chairHeight/2,z+chairDepth-backDepth);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight,z+chairDepth-backDepth);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight,z+chairDepth-backDepth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex3);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x,y+chairHeight/2-2,z);
			glTexCoord2d(1, 0);
			glVertex3d(x+chairWidth,y+chairHeight/2-2,z);
			glTexCoord2d(1, 1);
			glVertex3d(x+chairWidth,y+chairHeight/2,z);
			glTexCoord2d(0, 1);
			glVertex3d(x,y+chairHeight/2,z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
		glPopMatrix();
		return ;
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+chairWidth,y,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+chairWidth,y+chairHeight,z);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+chairHeight,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+chairWidth,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+chairWidth,y,z+chairDepth);
		glTexCoord2d(1, 1);
		glVertex3d(x+chairWidth,y+chairHeight/2+1,z+chairDepth);
		glTexCoord2d(0, 1);
		glVertex3d(x+chairWidth,y+chairHeight/2+1,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y,z+chairDepth);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+chairHeight/2+1,z+chairDepth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+chairHeight/2+1,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z+chairDepth+2);
		glTexCoord2d(1, 0);
		glVertex3d(x+chairWidth,y,z+chairDepth+2);
		glTexCoord2d(1, 1);
		glVertex3d(x+chairWidth,y+chairHeight/2,z+chairDepth+2);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+chairHeight/2,z+chairDepth+2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+chairHeight,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+chairWidth,y+chairHeight,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+chairWidth,y+chairHeight,z+backDepth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+chairHeight,z+backDepth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+chairHeight/2,z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y+chairHeight/2,z+backDepth);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+chairHeight,z+backDepth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+chairHeight,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+chairWidth,y+chairHeight/2,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+chairWidth,y+chairHeight/2,z+backDepth);
		glTexCoord2d(1, 1);
		glVertex3d(x+chairWidth,y+chairHeight,z+backDepth);
		glTexCoord2d(0, 1);
		glVertex3d(x+chairWidth,y+chairHeight,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex3);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+chairHeight/2,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+chairWidth,y+chairHeight/2,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+chairWidth,y+chairHeight/2,z+chairDepth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+chairHeight/2,z+chairDepth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex3);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+chairHeight/2,z+backDepth);
		glTexCoord2d(1, 0);
		glVertex3d(x+chairWidth,y+chairHeight/2,z+backDepth);
		glTexCoord2d(1, 1);
		glVertex3d(x+chairWidth,y+chairHeight,z+backDepth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+chairHeight,z+backDepth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex3);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+chairHeight/2-2,z+chairDepth);
		glTexCoord2d(1, 0);
		glVertex3d(x+chairWidth,y+chairHeight/2-2,z+chairDepth);
		glTexCoord2d(1, 1);
		glVertex3d(x+chairWidth,y+chairHeight/2,z+chairDepth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+chairHeight/2,z+chairDepth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glPopMatrix();
}


void trainTrailer::drawStand(float x,float y,float z,float w,float d,float h)
{
	float standWidth=w,standdepth=d,standHeight=h;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+standWidth,y,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+standWidth,y+standHeight,z);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+standHeight,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y,z+standdepth);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+standHeight,z+standdepth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+standHeight,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z+standdepth);
		glTexCoord2d(1, 0);
		glVertex3d(x+standWidth,y,z+standdepth);
		glTexCoord2d(1, 1);
		glVertex3d(x+standWidth,y+standHeight,z+standdepth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+standHeight,z+standdepth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+standWidth,y,z+standdepth);
		glTexCoord2d(1, 0);
		glVertex3d(x+standWidth,y,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+standWidth,y+standHeight,z);
		glTexCoord2d(0, 1);
		glVertex3d(x+standWidth,y+standHeight,z+standdepth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}


void trainTrailer::drawWheel(float x,float y,float z,int frontOrBack,int rightOrLeft)
{
	glColor4f(0,0,0,1);
	double radius = 3;
	double ori_z = z;                        
	double ori_y = y-2.2;
	double len=6*frontOrBack;
	double Len=0;
	double PI=3.14159265358979323846;
	float widhtOfWheel=3*rightOrLeft;
	for(int i=0;i<3;i++)
	{
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 300; i++)
		{
			double angle = 2 * PI * i / 300;
			double z = cos(angle) * radius;
			double y = sin(angle) * radius;
			glVertex3d(x, ori_y + y,ori_z+z+Len);
		}
		glEnd();
		for (int i = 0; i <= 360; i++)
		{
			double angle = 2 * PI * i / 360;
			double z = cos(angle) * radius;
			double y = sin(angle) * radius;
			glBegin(GL_LINES);
				glVertex3d(x, ori_y + y,ori_z+z+Len);
				glVertex3d(x+widhtOfWheel, ori_y + y,ori_z+z+Len);
			glEnd();
		}
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 300; i++)
		{
			double angle = 2 * PI * i / 300;
			double z = cos(angle) * radius;
			double y = sin(angle) * radius;
			glVertex3d(x+widhtOfWheel, ori_y + y,ori_z+z+Len);
		}
		glEnd();
		Len+=len;
	}

}


void trainTrailer::drawTrailer(int stuff)
{
	 glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	 if(stuff>=2&&stuff<=5)
	 {
		 drawSeatsTrailer();
	 }
	 if(stuff>=6&&stuff<=8)
	 {
		 drawResturantTrailer();
	 }
	 if(stuff>=9)
	 {
		
		drawChair(x+15,y,z+27,2);
		drawChair(x+3,y,z+27,2);
		drawChair(x-9,y,z+27,2);
		drawChair(x-21,y,z+27,2);
		drawChair(x-33,y,z+27,2);
	 }

	//ground	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x-2,y,z-2);
		glTexCoord2d(1, 0);
		glVertex3d(x+width+2,y,z-2);
		glTexCoord2d(1, 1);
		glVertex3d(x+width+2,y,z+depth+2);
		glTexCoord2d(0, 1);
		glVertex3d(x-2,y,z+depth+2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width/4,y,z+depth);
		glTexCoord2d(1, 0);
		glVertex3d(x+(width*3/4),y,z+depth);
		glTexCoord2d(1, 1);
		glVertex3d(x+(width*3/4),y,z+spaceBetween+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+width/4,y,z+spaceBetween+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	drawWheel(x-1,y-1,z,1,1);
	drawWheel(x+width+1,y-1,z,1,-1);
	drawWheel(x-1,y-1,z+depth,-1,1);
	drawWheel(x+width+1,y-1,z+depth,-1,-1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	//front with door
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width/4,y,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width/4,y+height,z);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+(width*3/4),y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z);
		glTexCoord2d(0, 1);
		glVertex3d(x+(width*3/4),y+height,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height*3/4),z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height*3/4),z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	if(!isOpen)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex2);
		glColor4f(0.2f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+width/4,y,z);
			glTexCoord2d(1, 0);
			glVertex3d(x+(width*3/4),y,z);
			glTexCoord2d(1, 1);
			glVertex3d(x+(width*3/4),y+(height*3/4),z);
			glTexCoord2d(0, 1);
			glVertex3d(x+width/4,y+(height*3/4),z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex2);
		glColor4f(0.2f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+width/4,y,z);
			glTexCoord2d(1, 0);
			glVertex3d(x+(width/4),y,z-(width/4));
			glTexCoord2d(1, 1);
			glVertex3d(x+(width/4),y+(height*3/4),z-(width/4));
			glTexCoord2d(0, 1);
			glVertex3d(x+width/4,y+(height*3/4),z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	//back face with door
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z+depth);
		glTexCoord2d(1, 0);
		glVertex3d(x+width/4,y,z+depth);
		glTexCoord2d(1, 1);
		glVertex3d(x+width/4,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+(width*3/4),y,z+depth);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y,z+depth);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+(width*3/4),y+height,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height*3/4),z+depth);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height*3/4),z+depth);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	if(!isOpen)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex2);
		glColor4f(0.2f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+width/4,y,z+depth);
			glTexCoord2d(1, 0);
			glVertex3d(x+(width*3/4),y,z+depth);
			glTexCoord2d(1, 1);
			glVertex3d(x+(width*3/4),y+(height*3/4),z+depth);
			glTexCoord2d(0, 1);
			glVertex3d(x+width/4,y+(height*3/4),z+depth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex2);
		glColor4f(0.2f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+width/4,y,z+depth);
			glTexCoord2d(1, 0);
			glVertex3d(x+(width/4),y,z+depth-(width/4));
			glTexCoord2d(1, 1);
			glVertex3d(x+(width/4),y+(height*3/4),z+depth-(width/4));
			glTexCoord2d(0, 1);
			glVertex3d(x+width/4,y+(height*3/4),z+depth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}


	//roof
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex);
	glColor4f(1.0f, 0.5f, 0.0f,1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x-2,y+height,z-2);
		glTexCoord2d(1, 0);
		glVertex3d(x+width+2,y+height,z-2);
		glTexCoord2d(1, 1);
		glVertex3d(x+width+2,y+height,z+depth+2);
		glTexCoord2d(0, 1);
		glVertex3d(x-2,y+height,z+depth+2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	//right
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y+(height/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+(height/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height*2/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y+height,z);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+(height*2/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y+(height*2/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+(height*2/3),z+depth/8);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+(height/3),z+depth/8);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height/3),z+(depth*7/8));
		glTexCoord2d(1, 0);
		glVertex3d(x,y+(height*2/3),z+(depth*7/8));
		glTexCoord2d(1, 1);
		glVertex3d(x,y+(height*2/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+(height/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	


	//left 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+(height/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y+(height*2/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+height,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y+(height*2/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y+(height/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height*2/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+(height*2/3),z+depth/8);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y+(height/3),z+depth/8);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y+(height/3),z+(depth*7/8));
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height*2/3),z+(depth*7/8));
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+(height*2/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y+(height/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//Right Window
	if(stuff >= 9)
	{
		glColor3f(1.0f,1.0f, 1.0f);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex5);
		glBegin(GL_QUADS);
		glTexCoord2d(1, 0);
		glVertex3d(x+0.3,y+(height/4),z+depth/8);
		glTexCoord2d(1, 1);
		glVertex3d(x+0.3,y+(height*3/3),z+depth/8);
		
		glTexCoord2d(0, 1);
		glVertex3d(x+0.3,y+(height*3/3),z+(depth*7/8));
		glTexCoord2d(0, 0);
		glVertex3d(x+0.3,y+(height/4),z+(depth*7/8));
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);

	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
	
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height/4),z+depth/8);
		glTexCoord2d(1, 0);
		glVertex3d(x,y+(height*3/3),z+depth/8);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+(height*3/3),z+(depth*7/8));
		glTexCoord2d(0, 1);
		glVertex3d(x,y+(height/4),z+(depth*7/8));
	glEnd();
	glDisable(GL_TEXTURE_2D);
	}
	else
	{
	glColor4f(1.0f,1.0f, 1.0f, transparency);
	glBegin(GL_QUADS);
		glVertex3d(x,y+(height/3),z+depth/8);
		glVertex3d(x,y+(height*2/3),z+depth/8);
		glVertex3d(x,y+(height*2/3),z+(depth*7/8));
		glVertex3d(x,y+(height/3),z+(depth*7/8));
	glEnd();
	}
	//left window
	glColor4f(1.0f,1.0f, 1.0f, transparency);
	glBegin(GL_QUADS);
		glVertex3d(x+width,y+(height/3),z+depth/8);
		glVertex3d(x+width,y+(height*2/3),z+depth/8);
		glVertex3d(x+width,y+(height*2/3),z+(depth*7/8));
		glVertex3d(x+width,y+(height/3),z+(depth*7/8));
	glEnd();
	
}

void trainTrailer::drawFirstTrailer()
{
	 glColor3f(1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex4);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+height/4,z+height/2);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+height/4,z+height/2);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height/3,z);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height/3,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z+height/2);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y,z+height/2);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height/4,z+height/2);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height/4,z+height/2);
	glEnd();float chairWidth=12,chairDepth=-6,chairHeight=10,backDepth=-1;
	float curZ=z-chairDepth*2;
	curZ-=5*chairDepth+1;
	drawChair(x+15,y,curZ-10,-1);
	

	 glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	//ground	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x-2,y,z-2);
		glTexCoord2d(1, 0);
		glVertex3d(x+width+2,y,z-2);
		glTexCoord2d(1, 1);
		glVertex3d(x+width+2,y,z+depth+2);
		glTexCoord2d(0, 1);
		glVertex3d(x-2,y,z+depth+2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width/4,y,z+depth);
		glTexCoord2d(1, 0);
		glVertex3d(x+(width*3/4),y,z+depth);
		glTexCoord2d(1, 1);
		glVertex3d(x+(width*3/4),y,z+spaceBetween+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+width/4,y,z+spaceBetween+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	drawWheel(x-1,y-1,z,1,1);
	drawWheel(x+width+1,y-1,z,1,-1);
	drawWheel(x-1,y-1,z+depth,-1,1);
	drawWheel(x+width+1,y-1,z+depth,-1,-1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	

	//back face with door
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z+depth);
		glTexCoord2d(1, 0);
		glVertex3d(x+width/4,y,z+depth);
		glTexCoord2d(1, 1);
		glVertex3d(x+width/4,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+(width*3/4),y,z+depth);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y,z+depth);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+(width*3/4),y+height,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height*3/4),z+depth);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height*3/4),z+depth);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	if(!isOpen)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex2);
		glColor4f(0.2f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+width/4,y,z+depth);
			glTexCoord2d(1, 0);
			glVertex3d(x+(width*3/4),y,z+depth);
			glTexCoord2d(1, 1);
			glVertex3d(x+(width*3/4),y+(height*3/4),z+depth);
			glTexCoord2d(0, 1);
			glVertex3d(x+width/4,y+(height*3/4),z+depth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex2);
		glColor4f(0.2f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+width/4,y,z+depth);
			glTexCoord2d(1, 0);
			glVertex3d(x+(width/4),y,z+depth-(width/4));
			glTexCoord2d(1, 1);
			glVertex3d(x+(width/4),y+(height*3/4),z+depth-(width/4));
			glTexCoord2d(0, 1);
			glVertex3d(x+width/4,y+(height*3/4),z+depth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	//front face 
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height/3,z);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height/3,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(2*height)/3,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(2*height)/3,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+height/3,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width/6,y+height/3,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width/6,y+(2*height)/3,z);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+(2*height)/3,z);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+(width*5/6),y+height/3,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+height/3,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+(2*height)/3,z);
		glTexCoord2d(0, 1);
		glVertex3d(x+(width*5/6),y+(2*height)/3,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	//roof

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex);
	glColor4f(1.0f, 0.5f, 0.0f,1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x-2,y+height,z-2);
		glTexCoord2d(1, 0);
		glVertex3d(x+width+2,y+height,z-2);
		glTexCoord2d(1, 1);
		glVertex3d(x+width+2,y+height,z+depth+2);
		glTexCoord2d(0, 1);
		glVertex3d(x-2,y+height,z+depth+2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	drawStand(x+width/2,y+height,z+10,4,4,16);
	//right
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y+(height/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+(height/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height*2/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y+height,z);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+(height*2/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y+(height*2/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+(height*2/3),z+depth/8);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+(height/3),z+depth/8);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height/3),z+(depth*7/8));
		glTexCoord2d(1, 0);
		glVertex3d(x,y+(height*2/3),z+(depth*7/8));
		glTexCoord2d(1, 1);
		glVertex3d(x,y+(height*2/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+(height/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	


	//left with window 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+(height/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y+(height*2/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+height,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y+(height*2/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y+(height/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height*2/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+(height*2/3),z+depth/8);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y+(height/3),z+depth/8);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y+(height/3),z+(depth*7/8));
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height*2/3),z+(depth*7/8));
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+(height*2/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y+(height/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//left window
	glColor4f(1.0f,1.0f, 1.0f, transparency);
	glBegin(GL_QUADS);
		glVertex3d(x+width,y+(height/3),z+depth/8);
		glVertex3d(x+width,y+(height*2/3),z+depth/8);
		glVertex3d(x+width,y+(height*2/3),z+(depth*7/8));
		glVertex3d(x+width,y+(height/3),z+(depth*7/8));
	glEnd();
	////front window
	glColor4f(1.0f, 1.5f, 1.0f,transparency);
	glBegin(GL_QUADS);
		glVertex3d(x+width/6,y+height/3,z);
		glVertex3d(x+(width*5/6),y+height/3,z);
		glVertex3d(x+(width*5/6),y+(2*height)/3,z);
		glVertex3d(x+width/6,y+(2*height)/3,z);
	glEnd();
	//Right Window
	glColor4f(1.0f,1.0f, 1.0f, transparency);
	glBegin(GL_QUADS);
		glVertex3d(x,y+(height/3),z+depth/8);
		glVertex3d(x,y+(height*2/3),z+depth/8);
		glVertex3d(x,y+(height*2/3),z+(depth*7/8));
		glVertex3d(x,y+(height/3),z+(depth*7/8));
	glEnd();
}

void trainTrailer::drawLastTrailer()
{
	drawSeatsTrailer();
	 glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	//ground	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x-2,y,z-2);
		glTexCoord2d(1, 0);
		glVertex3d(x+width+2,y,z-2);
		glTexCoord2d(1, 1);
		glVertex3d(x+width+2,y,z+depth+2);
		glTexCoord2d(0, 1);
		glVertex3d(x-2,y,z+depth+2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	drawWheel(x-1,y-1,z,1,1);
	drawWheel(x+width+1,y-1,z,1,-1);
	drawWheel(x-1,y-1,z+depth,-1,1);
	drawWheel(x+width+1,y-1,z+depth,-1,-1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	//front with door
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width/4,y,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width/4,y+height,z);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+(width*3/4),y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z);
		glTexCoord2d(0, 1);
		glVertex3d(x+(width*3/4),y+height,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height*3/4),z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height*3/4),z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	if(!isOpen)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex2);
		glColor4f(0.2f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+width/4,y,z);
			glTexCoord2d(1, 0);
			glVertex3d(x+(width*3/4),y,z);
			glTexCoord2d(1, 1);
			glVertex3d(x+(width*3/4),y+(height*3/4),z);
			glTexCoord2d(0, 1);
			glVertex3d(x+width/4,y+(height*3/4),z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex2);
		glColor4f(0.2f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+width/4,y,z);
			glTexCoord2d(1, 0);
			glVertex3d(x+(width/4),y,z-(width/4));
			glTexCoord2d(1, 1);
			glVertex3d(x+(width/4),y+(height*3/4),z-(width/4));
			glTexCoord2d(0, 1);
			glVertex3d(x+width/4,y+(height*3/4),z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	//back face with door
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z+depth);
		glTexCoord2d(1, 0);
		glVertex3d(x+width/4,y,z+depth);
		glTexCoord2d(1, 1);
		glVertex3d(x+width/4,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+(width*3/4),y,z+depth);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y,z+depth);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+(width*3/4),y+height,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height*3/4),z+depth);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height*3/4),z+depth);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+height,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	if(!isOpen)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex2);
		glColor4f(0.2f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+width/4,y,z+depth);
			glTexCoord2d(1, 0);
			glVertex3d(x+(width*3/4),y,z+depth);
			glTexCoord2d(1, 1);
			glVertex3d(x+(width*3/4),y+(height*3/4),z+depth);
			glTexCoord2d(0, 1);
			glVertex3d(x+width/4,y+(height*3/4),z+depth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureIndex2);
		glColor4f(0.2f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x+width/4,y,z+depth);
			glTexCoord2d(1, 0);
			glVertex3d(x+(width/4),y,z+depth-(width/4));
			glTexCoord2d(1, 1);
			glVertex3d(x+(width/4),y+(height*3/4),z+depth-(width/4));
			glTexCoord2d(0, 1);
			glVertex3d(x+width/4,y+(height*3/4),z+depth);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	 
	//roof
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex);
	glColor4f(1.0f, 0.5f, 0.0f,1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x-2,y+height,z-2);
		glTexCoord2d(1, 0);
		glVertex3d(x+width+2,y+height,z-2);
		glTexCoord2d(1, 1);
		glVertex3d(x+width+2,y+height,z+depth+2);
		glTexCoord2d(0, 1);
		glVertex3d(x-2,y+height,z+depth+2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//right
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y+(height/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+(height/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height*2/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y+height,z);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+(height*2/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x,y+(height*2/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x,y+(height*2/3),z+depth/8);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+(height/3),z+depth/8);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x,y+(height/3),z+(depth*7/8));
		glTexCoord2d(1, 0);
		glVertex3d(x,y+(height*2/3),z+(depth*7/8));
		glTexCoord2d(1, 1);
		glVertex3d(x,y+(height*2/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x,y+(height/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//left
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y,z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+(height/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y,z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y+(height*2/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+height,z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+height,z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y+(height*2/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y+(height/3),z);
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height*2/3),z);
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+(height*2/3),z+depth/8);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y+(height/3),z+depth/8);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIndex1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x+width,y+(height/3),z+(depth*7/8));
		glTexCoord2d(1, 0);
		glVertex3d(x+width,y+(height*2/3),z+(depth*7/8));
		glTexCoord2d(1, 1);
		glVertex3d(x+width,y+(height*2/3),z+depth);
		glTexCoord2d(0, 1);
		glVertex3d(x+width,y+(height/3),z+depth);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//left window
	glColor4f(1.0f,1.0f, 1.0f, transparency);
	glBegin(GL_QUADS);
		glVertex3d(x+width,y+(height/3),z+depth/8);
		glVertex3d(x+width,y+(height*2/3),z+depth/8);
		glVertex3d(x+width,y+(height*2/3),z+(depth*7/8));
		glVertex3d(x+width,y+(height/3),z+(depth*7/8));
	glEnd();
	//Right Window
	glColor4f(1.0f,1.0f, 1.0f, transparency);
	glBegin(GL_QUADS);
		glVertex3d(x,y+(height/3),z+depth/8);
		glVertex3d(x,y+(height*2/3),z+depth/8);
		glVertex3d(x,y+(height*2/3),z+(depth*7/8));
		glVertex3d(x,y+(height/3),z+(depth*7/8));
	glEnd();
}
