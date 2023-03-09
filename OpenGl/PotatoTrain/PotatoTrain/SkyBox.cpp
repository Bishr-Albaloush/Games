#include "SkyBox.h"
SkyBox::SkyBox()
{

}

SkyBox::SkyBox(float size,int sky,int ground,int face)
{
	this->size = size;
	this->sky=sky;
	this->ground=ground;
	this->face=face;
	start=-size-35;
	end=size+100;
	curZ=start;
	start1=-size-35;
	end1=end;
	curZ1=start-movment*3;
	Leaf.LoadBMP("leaf.bmp");
	Bark.LoadBMP("Bark.bmp");
	movment=20;
	for(int i=0;i<4;i++)
	{
		tree[i]= new Model_3DS ( );
		tree[i]->Load("tree.3ds");
		tree[i]->pos.x=100;
		tree[i]->pos.y=0;
		tree[i]->pos.z=curZ;
		tree[i]->Materials[0].tex=Bark;
		tree[i]->Materials[1].tex=Leaf;
	}
	tree[1]->pos.x=-100;
	tree[2]->pos.x=-100;
	tree[2]->pos.z=curZ-100;
	tree[3]->pos.x=400;

	tree[4]= new Model_3DS ( );
	tree[4]->Load("tree.3ds");
	tree[4]->pos.x=150;
	tree[4]->pos.y=0;
	tree[4]->pos.z=curZ1-100;
	tree[4]->Materials[0].tex=Bark;
	tree[4]->Materials[1].tex=Leaf;
	tree[5]= new Model_3DS ( );
	tree[5]->Load("tree.3ds");
	tree[5]->pos.x=-150;
	tree[5]->pos.y=0;
	tree[5]->pos.z=curZ1;
	tree[5]->Materials[0].tex=Bark;
	tree[5]->Materials[1].tex=Leaf;
	isMoving=false;
}
void SkyBox::stopStart()
{
	if (isMoving){isMoving = false;
	PlaySound(NULL, NULL, 0);}
	else{
		isMoving=true;
	PlaySound("train.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);}
}

void SkyBox::drawTree()
{
	for(int i=0;i<4;i++)
	{
		tree[i]->pos.z=curZ;
		tree[i]->Draw();
	}
	for(int i=4;i<6;i++)
	{
		tree[i]->pos.z=curZ1;
		tree[i]->Draw();
	}
	if(isMoving)
	{
		curZ+=movment;
		curZ1+=movment;
		if(curZ>end)
		{
			curZ=start;
		}
		if(curZ1>end1)
		{
			curZ1=start1;
		}
	}
}

void SkyBox::draw()
{
	drawTree();
	glColor4d(1,1,1,1);
	//ground
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ground);
	glBegin(GL_QUADS);	
		glTexCoord2d(0, 0);
		glVertex3d(-size,-2,-size);
		glTexCoord2d(1, 0);
		glVertex3d(-size,-2,+size);
		glTexCoord2d(1, 1);
		glVertex3d(+size,-2,+size);
		glTexCoord2d(0, 1);
		glVertex3d(+size,-2,-size);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//back face of cube
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, face);
	glBegin(GL_QUADS);		
		glTexCoord2d(0, 0);
		glVertex3d(-size,-2,+size);
		glTexCoord2d(0, 1);
		glVertex3d(-size,size,+size);
		glTexCoord2d(1, 1);
		glVertex3d(+size,size,+size);
		glTexCoord2d(1, 0);
		glVertex3d(+size,-2,+size);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//front face of cube
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, face);
	glBegin(GL_QUADS);		
		glTexCoord2d(0, 0);
		glVertex3d(-size,-2,-size);
		glTexCoord2d(0, 1);
		glVertex3d(-size,size,-size);
		glTexCoord2d(1, 1);
		glVertex3d(+size,size,-size);
		glTexCoord2d(1, 0);
		glVertex3d(+size,-2,-size);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//sky
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, sky);
	glBegin(GL_QUADS);	
		glTexCoord2d(0, 0);
		glVertex3d(-size,size,-size);
		glTexCoord2d(1, 0);
		glVertex3d(-size,size,+size);
		glTexCoord2d(1, 1);
		glVertex3d(+size,size,+size);
		glTexCoord2d(0, 1);
		glVertex3d(+size,size,-size);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//right
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, face);
	glBegin(GL_QUADS);	
		glTexCoord2d(0, 0);
		glVertex3d(+size,-2,+size);
		glTexCoord2d(0, 1);
		glVertex3d(+size,size,+size);
		glTexCoord2d(1, 1);
		glVertex3d(+size,size,-size);
		glTexCoord2d(1, 0);
		glVertex3d(+size,-2,-size);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//left
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, face);
	glBegin(GL_QUADS);	
		glTexCoord2d(0, 0);
		glVertex3d(-size,-2,+size);
		glTexCoord2d(0, 1);
		glVertex3d(-size,size,+size);
		glTexCoord2d(1, 1);
		glVertex3d(-size,size,-size);
		glTexCoord2d(1, 0);
		glVertex3d(-size,-2,-size);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void SkyBox::moveground()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ground);
	glBegin(GL_QUADS);	
		glTexCoord2d(0, 0);
		glVertex3d(-size,-2,-size);
		glTexCoord2d(1, 0);
		glVertex3d(-size,-2,+size);
		glTexCoord2d(1, 1);
		glVertex3d(+size,-2,+size);
		glTexCoord2d(0, 1);
		glVertex3d(+size,-2,-size);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
