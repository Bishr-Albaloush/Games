#include <cmath>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>
#include <GL/glut.h>
#include "SkyBox.h"
#include "camera.h"
#include "trainTrailer.h"
#include "texture.h"
#include "railWay.h"
#include "Model_3DS.h"
#include <algorithm>
#include "3DTexture.h"
#include <GLFW/glfw3.h>


HDC hDC = NULL; // Private GDI Device Context
HGLRC hRC = NULL; // Permanent Rendering Context
HWND hWnd = NULL; // Holds Our Window Handle
HINSTANCE hInstance; // Holds The Instance Of The Application

bool keys[256]; // Array Used For The Keyboard Routine
bool active = TRUE; // Window Active Flag Set To TRUE By Default
bool fullscreen = TRUE; // Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height) // Resize And Initialize The GL Window
{
	if (height == 0) // Prevent A Divide By Zero By
	{
		height = 1; // Making Height Equal One
	}

	glViewport(0, 0, width, height); // Reset The Current Viewport

	glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
	glLoadIdentity(); // Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 5000.0f);

	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity(); // Reset The Modelview Matrix
}

float speed,skyBoxSize,mouseSpeed;
Camera MyCamera;
float mouseX,mouseY,MX,MY;
bool isClicked,isRClicked,isOpenDoor;
int woodImage,woodImage1,doorImage,trailerCounter,controlImage,movieImage;
int skyImage,groundImage,grassWithSkyImage,railWayImage,seat;
float widthOfTrailer,heightOfTrailer,depthOfTrailer,spaceBetweenTrailer;
trainTrailer* train=new trainTrailer[12];
SkyBox skyBox1;
float trainSpeed;
bool startOfScene;
void init()
{
	GLfloat MatAmb[] = {1,0,0,1};
	GLfloat MatDiff[] = {0.2,0.6,0.9,1};
	GLfloat MatSpec[] = {0,0,0,1};
	GLfloat MatShn[] = {128};
	glMaterialfv(GL_FRONT,GL_AMBIENT,MatAmb);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MatDiff);
    glMaterialfv(GL_FRONT,GL_SPECULAR,MatSpec);
    glMaterialfv(GL_FRONT,GL_SHININESS,MatShn);
    glEnable(GL_COLOR_MATERIAL);
	MyCamera = Camera();
	MyCamera.Position.x=0;
	MyCamera.Position.y=0;
	MyCamera.Position.z=0;
	speed=5;
	trailerCounter=0;
	mouseX=0;
	mouseY=0;
	MX=0;
	MY=0;
	isClicked=0;
	isRClicked=0;
	skyBoxSize=2000;
	mouseSpeed=8;
	widthOfTrailer=40;
	heightOfTrailer=30;
	depthOfTrailer=60;
	spaceBetweenTrailer=depthOfTrailer+15;
	isOpenDoor=false;
	woodImage=LoadTexture("wood.bmp",255);
	woodImage1=LoadTexture("wood1.bmp",255);
	doorImage=LoadTexture("door.bmp",255);
	skyImage=LoadTexture("sky.bmp",255);
	controlImage = LoadTexture("control.bmp",255);
	movieImage = LoadTexture("movie.bmp",255);
	groundImage=LoadTexture("ground.bmp",255);
	grassWithSkyImage=LoadTexture("face.bmp",255);
	railWayImage=LoadTexture("railWay.bmp",255);
	seat=LoadTexture("seat.bmp",255);
	woodImage=grassWithSkyImage;

	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	startOfScene=false;
	int curZ=-200;
	train[1]=trainTrailer(0,4,curZ,woodImage,woodImage1,doorImage,seat,controlImage,movieImage,widthOfTrailer,heightOfTrailer,depthOfTrailer,isOpenDoor);
	curZ+=spaceBetweenTrailer;
	trailerCounter++;
	for(int i=2;i<=9;i++,trailerCounter++)
	{
		train[i]=trainTrailer(0,4,curZ,woodImage,woodImage1,doorImage,seat,controlImage,movieImage,widthOfTrailer,heightOfTrailer,depthOfTrailer,isOpenDoor);
		curZ+=spaceBetweenTrailer;
	}
	train[10]=trainTrailer(0,4,curZ,woodImage,woodImage1,doorImage,seat,controlImage,movieImage,widthOfTrailer,heightOfTrailer,depthOfTrailer,isOpenDoor);
	skyBox1=SkyBox(skyBoxSize,skyImage,groundImage,grassWithSkyImage);
}

static float lastx = 0.0;
static float lasty = 0.0;

void mouseMovement(int x, int y) 
{


    lastx = (float)x - lastx;
    lasty = (float)y - lasty;

    if((abs((int)lastx)>10)||(abs((int)lasty)>10))
    {
        lastx = (float)x;
        lasty = (float)y;
        return;
    }
	if((float)x > lastx)
        MyCamera.RotateY((-lastx));
    else
        MyCamera.RotateY(lastx);
    if((float)y > lasty)
        MyCamera.RotateX(-lasty);
    else 
        MyCamera.RotateX(lasty); 
    lastx = (float)x;
    lasty = (float)y;
}

void control(int mouseX,int mouseY,bool isClicked,bool isRClicked)
{

	if(startOfScene)
	{
		if(keys['W'])
			MyCamera.MoveForward(speed);
		if(keys['D'])
			MyCamera.MoveRight(speed);
		if(keys['A'])
			MyCamera.MoveLeft(speed);
		if(keys['S'])
			MyCamera.MoveBack(speed);
		if(keys['Z'])
			MyCamera.MoveUpward(speed);
		if(keys['X'])
			MyCamera.MoveUpward(-speed);
		if(keys['G'])
			skyBox1.stopStart();
		if(keys['E'])
		{
			isOpenDoor^=1;
			for(int i=1;i<=trailerCounter;i++)
				train[i].isOpen=isOpenDoor;
			train[10].isOpen=isOpenDoor;
		}
		if(keys[VK_SPACE])
			MyCamera.MoveUpward(speed);
		if (keys[VK_DOWN])
			MyCamera.RotateX(-mouseSpeed);
		if (keys[VK_UP])
			MyCamera.RotateX(mouseSpeed);
		if (keys[VK_LEFT])
			MyCamera.RotateY(mouseSpeed);
		if (keys[VK_RIGHT])
			MyCamera.RotateY(-mouseSpeed);
		if (isClicked)
			MyCamera.RotateY(-mouseSpeed);
		if (isRClicked)
			MyCamera.RotateY(mouseSpeed);
		if((isClicked&&isRClicked)&&keys['V'])
		{
			MyCamera.RotateX(-mouseSpeed);
		}
		if((isClicked&&isRClicked)&&!keys['V'])
		{
			MyCamera.RotateX(mouseSpeed);
		}
		if(!(isClicked||isRClicked))
		{
			MyCamera.reset();
		}
		mouseMovement(mouseX, mouseY);
		
		MyCamera.Render();
	}
	else
	{
		if(keys['H'])
			startOfScene=true;
	}
	if(keys[VK_ESCAPE])
			exit(0);
}

void Light1()
{
	GLfloat LightPos[] = {0,skyBoxSize,-skyBoxSize,1};
	GLfloat LightAmb[] = {1,1,1,1};
	GLfloat LightDiff[] = {0.6,0.6,0.6,1};
	GLfloat LightSpec[] = {-0.2,-0.2,-0.2,1};
	glLightfv(GL_LIGHT1,GL_POSITION,LightPos);
	glLightfv(GL_LIGHT1,GL_AMBIENT,LightAmb);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,LightDiff);
	glLightfv(GL_LIGHT1,GL_SPECULAR,LightSpec);
	glEnable (GL_LIGHT1);
	glEnable (GL_LIGHTING);
}
void Light2()
{
	GLfloat LightPos[] = {0,skyBoxSize,skyBoxSize,1};
	GLfloat LightAmb[] = {0,0,0,1};
	GLfloat LightDiff[] = {0.6,0.6,0.6,1};
	GLfloat LightSpec[] = {-0.2,-0.2,-0.2,1};
	glLightfv(GL_LIGHT2,GL_POSITION,LightPos);
	glLightfv(GL_LIGHT2,GL_AMBIENT,LightAmb);
	glLightfv(GL_LIGHT2,GL_DIFFUSE,LightDiff);
	glLightfv(GL_LIGHT2,GL_SPECULAR,LightSpec);
	glEnable (GL_LIGHT2);
	glEnable (GL_LIGHTING);
}

void drawBitmapText(char *string,float x,float y,float z) {    char *c;  glRasterPos3f(x, y,z);   for (c=string; *c != '\0'; c++)   {     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);   } }
void Logic()
{
	control(mouseX, mouseY,isClicked,isRClicked);
	//glutSetCursor(GLUT_CURSOR_NONE);
	//glfwCreateStandardCursor(GLFW_CURSOR_DISABLED);
	//glutWarpPointer(0, 0);

	if(startOfScene)
	{
		glTranslated(0,-100,-100);
		Light1();
		Light2();
	
		skyBox1.draw();
		railWay RailWay(widthOfTrailer,-1.99,skyBoxSize,railWayImage);
		RailWay.drawRailWay();	
		glPushMatrix();
		if (skyBox1.isMoving)
			{
				trainSpeed += (speed+1);
			
				if(trainSpeed >= skyBoxSize/2){
					trainSpeed=0;
					

				}
		}

		else
			trainSpeed = 0;
		glTranslated(0,0,trainSpeed);
		skyBox1.moveground();
		RailWay.drawRailWay();	
	
		glPopMatrix();
		train[1].drawFirstTrailer();
		for(int i=2;i<=trailerCounter;i++)
		{
			train[i].drawTrailer(i);
		}
		train[10].drawLastTrailer();
	}
	else
	{
		glPushMatrix();
		glTranslated(0,0,-5);
		glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // Black Background
		glColor3d(0,1,0);
		drawBitmapText("Train Simulation",-0.3,1.5,0);
		glColor3d(1,1,1);
		drawBitmapText("To Start the Scene press 'H'",-1.5,1.0,0);
		drawBitmapText("To Move the train press 'G'",-1.5,0.5,0);
		drawBitmapText("To Open the doors press 'E'",-1.5,0.0,0);
		drawBitmapText("To Move the camera use 'W,S,A,D,Z,X'",-1.5,-0.5,0);
		drawBitmapText("To Move the view use arrows or mouse",-1.5,-1,0);
		glColor3d(1,0,0);
		drawBitmapText("To Exit the Scene press 'Esc'",-1.5,-1.5,0);
		glColor3d(1,1,1);
		glPopMatrix();
	}

	
	
	
}

int InitGL(GLvoid) // All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH); // Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // Black Background
	glClearDepth(1.0f); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
	init();
	return TRUE; // Initialization Went OK
}

// Here's Where We Do All The Drawing

void DrawGLScene(){
  //Clear information from last draw
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
  glLoadIdentity(); //Reset the drawing perspective

  Logic();
  SwapBuffers(hDC); //Send the 3D scene to the screen
}

GLvoid KillGLWindow(GLvoid) // Properly Kill The Window
{
	if (fullscreen) // Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0); // If So Switch Back To The Desktop
		ShowCursor(TRUE); // Show Mouse Pointer
	}

	if (hRC) // Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL)) // Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC)) // Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL; // Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC)) // Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL; // Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd)) // Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL; // Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance)) // Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL; // Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, byte bits, bool fullscreenflag)
{
	GLuint PixelFormat; // Holds The Results After Searching For A Match
	WNDCLASS wc; // Windows Class Structure
	DWORD dwExStyle; // Window Extended Style
	DWORD dwStyle; // Window Style
	RECT WindowRect; // Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0; // Set Left Value To 0
	WindowRect.right = (long)width; // Set Right Value To Requested Width
	WindowRect.top = (long)0; // Set Top Value To 0
	WindowRect.bottom = (long)height; // Set Bottom Value To Requested Height

	fullscreen = fullscreenflag; // Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL); // Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc; // WndProc Handles Messages
	wc.cbClsExtra = 0; // No Extra Window Data
	wc.cbWndExtra = 0; // No Extra Window Data
	wc.hInstance = hInstance; // Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO); // Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Load The Arrow Pointer
	wc.hbrBackground = NULL; // No Background Required For GL
	wc.lpszMenuName = NULL; // We Don't Want A Menu
	wc.lpszClassName = "OpenGL"; // Set The Class Name

	if (!RegisterClass(&wc)) // Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (fullscreen) // Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings; // Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings)); // Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings); // Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width; // Selected Screen Width
		dmScreenSettings.dmPelsHeight = height; // Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits; // Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(
				NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?",
				"NeHe GL", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE; // Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE; // Return FALSE
			}
		}
	}

	if (fullscreen) // Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW; // Window Extended Style
		dwStyle = WS_POPUP; // Windows Style
		ShowCursor(FALSE); // Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE; // Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW; // Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle); // Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle, // Extended Style For The Window
	                            "OpenGL", // Class Name
	                            title, // Window Title
	                            dwStyle | // Defined Window Style
	                            WS_CLIPSIBLINGS | // Required Window Style
	                            WS_CLIPCHILDREN, // Required Window Style
	                            0, 0, // Window Position
	                            WindowRect.right - WindowRect.left, // Calculate Window Width
	                            WindowRect.bottom - WindowRect.top, // Calculate Window Height
	                            NULL, // No Parent Window
	                            NULL, // No Menu
	                            hInstance, // Instance
	                            NULL))) // Dont Pass Anything To WM_CREATE
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	static PIXELFORMATDESCRIPTOR pfd = // pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR), // Size Of This Pixel Format Descriptor
		1, // Version Number
		PFD_DRAW_TO_WINDOW | // Format Must Support Window
		PFD_SUPPORT_OPENGL | // Format Must Support OpenGL
		PFD_DOUBLEBUFFER, // Must Support Double Buffering
		PFD_TYPE_RGBA, // Request An RGBA Format
		bits, // Select Our Color Depth
		0, 0, 0, 0, 0, 0, // Color Bits Ignored
		0, // No Alpha Buffer
		0, // Shift Bit Ignored
		0, // No Accumulation Buffer
		0, 0, 0, 0, // Accumulation Bits Ignored
		16, // 16Bit Z-Buffer (Depth Buffer)  
		0, // No Stencil Buffer
		0, // No Auxiliary Buffer
		PFD_MAIN_PLANE, // Main Drawing Layer
		0, // Reserved
		0, 0, 0 // Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd))) // Did We Get A Device Context?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd))) // Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd)) // Are We Able To Set The Pixel Format?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC))) // Are We Able To Get A Rendering Context?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC)) // Try To Activate The Rendering Context
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW); // Show The Window
	SetForegroundWindow(hWnd); // Slightly Higher Priority
	SetFocus(hWnd); // Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height); // Set Up Our Perspective GL Screen

	if (!InitGL()) // Initialize Our Newly Created GL Window
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	return TRUE; // Success
}

LRESULT CALLBACK WndProc(HWND hWnd, // Handle For This Window
                         UINT uMsg, // Message For This Window
                         WPARAM wParam, // Additional Message Information
                         LPARAM lParam) // Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg) // Check For Windows Messages
	{
	case WM_PAINT:
		DrawGLScene();
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_TIMER:
		DrawGLScene();
		return 0;

	case WM_ACTIVATE: // Watch For Window Activate Message
		{
			if (!HIWORD(wParam)) // Check Minimization State
			{
				active = TRUE; // Program Is Active
			}
			else
			{
				active = FALSE; // Program Is No Longer Active
			}

			return 0; // Return To The Message Loop
		}
	case WM_MOUSEMOVE:
	{
		mouseX = (int)LOWORD(lParam);
		mouseY = (int)HIWORD(lParam);
		MX=(int)LOWORD(lParam);
		MY=(int)LOWORD(lParam);
		isClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
		isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
		break;
	}

	case WM_SYSCOMMAND: // Intercept System Commands
		{
			switch (wParam) // Check System Calls
			{
			case SC_SCREENSAVE: // Screensaver Trying To Start?
			case SC_MONITORPOWER: // Monitor Trying To Enter Powersave?
				return 0; // Prevent From Happening
			}
			break; // Exit
		}

	case WM_CLOSE: // Did We Receive A Close Message?
		{
			PostQuitMessage(0); // Send A Quit Message
			return 0; // Jump Back
		}

	case WM_KEYDOWN: // Is A Key Being Held Down?
		{
			keys[wParam] = TRUE; // If So, Mark It As TRUE
			return 0; // Jump Back
		}

	case WM_KEYUP: // Has A Key Been Released?
		{
			keys[wParam] = FALSE; // If So, Mark It As FALSE
			return 0; // Jump Back
		}

	case WM_SIZE: // Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam), HIWORD(lParam)); // LoWord=Width, HiWord=Height
			return 0; // Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, // Instance
                   HINSTANCE hPrevInstance, // Previous Instance
                   LPSTR lpCmdLine, // Command Line Parameters
                   int nCmdShow) // Window Show State
{
	MSG msg; // Windows Message Structure
	BOOL done = FALSE; // Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE; // Windowed Mode
	}

	// Create Our OpenGL Window
	char c[] = "";
	if (!CreateGLWindow(c, 640, 480, 16, fullscreen))
	{
		return 0; // Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer = SetTimer(hWnd, 0, 50, (TIMERPROC)NULL);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
