#include <cmath>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>
#include <texture.h>
#include "Dino.h"

using namespace std;

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
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity(); // Reset The Modelview Matrix
}
int img1, img2, img3, img4, img5, img6, img7, img8, img9, img10;
int InitGL(GLvoid) // All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH); // Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // Black Background
	glClearDepth(1.0f); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
	glEnable(GL_TEXTURE_2D);
	img1 = LoadTexture("DinoStart.bmp", 255);
	img2 = LoadTexture("img2.bmp", 255);
	img3 = LoadTexture("img3.bmp", 255);
	img4 = LoadTexture("img4.bmp", 255);
	img5 = LoadTexture("img5.bmp", 255);
	img6 = LoadTexture("img6.bmp", 255);
	img7 = LoadTexture("img7.bmp", 255);
	img8 = LoadTexture("img8.bmp", 255);
	img9 = LoadTexture("img9.bmp", 255);
	img10 = LoadTexture("img10.bmp", 255);
	return TRUE; // Initialization Went OK
}

// Here's Where We Do All The Drawing
GLfloat trans=0.0;
int i=1, counter=0, counter2=0;
GLfloat transtow=0.0;
bool jumb = false;
bool donejumb = false,start=false, lose=false;
float cord1x,cord1y,cord2x,cord2y,cord3x,cord3y,cord4x,cord4y;
float width;
float a=0.2;
void DrawGLScene(){
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
  
  
	glClearColor(255,255,255,255);
  
	glColor3f(0,0,0);
	glTranslatef(0,0,-5);
	glBegin(GL_LINES);
		glVertex2d(-4,-1.3);
		glVertex2d(4,-1.3);
	glEnd();
	glPushMatrix();
	 if(!start){
		 glBindTexture(GL_TEXTURE_2D, img1);
	
	 cord1x=0,cord1y=0,cord2x=0.8,cord2y=0,cord3x=1.25,cord3y=1,cord4x=0.4,cord4y=1;
	 }
	 else if(!lose && !jumb &&counter%2 == 0){glBindTexture(GL_TEXTURE_2D, img9);
	 cord1x=0,cord1y=0,cord2x=1,cord2y=0,cord3x=1,cord3y=1,cord4x=0,cord4y=1;}
	 else if(!lose && !jumb){glBindTexture(GL_TEXTURE_2D, img8);
	 cord1x=0,cord1y=0,cord2x=0.8,cord2y=0,cord3x=2,cord3y=1,cord4x=1.1,cord4y=1;}

	 else if(!lose){glBindTexture(GL_TEXTURE_2D, img7);
	 cord1x=0,cord1y=0,cord2x=1,cord2y=0,cord3x=1,cord3y=1,cord4x=0,cord4y=1;}
	 else{glBindTexture(GL_TEXTURE_2D, img10);
	 cord1x=0,cord1y=0,cord2x=0.7,cord2y=0,cord3x=1.75,cord3y=1,cord4x=1,cord4y=1;}
	glColor3ub(255,255,255);
	
	if(jumb){
		if(!donejumb){
			transtow += 0.25;}
		if (transtow >= 2 && !donejumb)
		{
			donejumb = true;
			
		}
		else if (transtow > 0.2 && donejumb)
		{
			transtow -= 0.25;
		}
		else if(donejumb)
		{
			jumb = false;
			donejumb =false;
		}
	}

	if(!jumb && !lose && start)
	{
		if(keys[VK_SPACE]){
		  jumb = true;
		}}
	
	if(lose)
	{
		if(keys[VK_SPACE]){
		  lose = false;
		  i = 1;
		  trans = 0;
		  transtow = 0;
		  start = false;
		}}
	glTranslated(0,transtow,0);
	
	Dino::DrawDino(Point::Point(-2,-1,0), 0.8, 1, Point::Point(cord1x,cord1y,0), Point::Point(cord2x,cord2y,0), Point::Point(cord3x,cord3y,0), Point::Point(cord4x,cord4y,0));
	
	glPopMatrix();
	if(!start && !lose){
		if(keys[VK_UP]){
		start=true;}
	}
	else{
	
	glPushMatrix();
		if(trans>-6.3 && trans<-5.3)
	{
		if(transtow<1.1){
		lose = true;
		jumb=false;
		donejumb=false;}
	}
		if(counter2 % 10 == 0){
			a += 0.001;}
	if(!lose){
		trans -= a;
		counter++;}
		glTranslated(trans,0,0);
 
		if (trans < -8.5){
			counter2++;
			trans = 2;
		i = rand()%3+1;	 
		}
		if(i==1){
				glBindTexture(GL_TEXTURE_2D, img2);
				width = 0.5;
			cord1x=0,cord1y=0,cord2x=1,cord2y=0,cord3x=1,cord3y=1,cord4x=0,cord4y=1;
				glColor3ub(255,255,255);
			}
		else if(i==2){
				glBindTexture(GL_TEXTURE_2D, img5);
				width = 1.2;
				cord1x=0,cord1y=0,cord2x=1,cord2y=0,cord3x=1,cord3y=1,cord4x=0,cord4y=1;
				glColor3ub(255,255,255);
			}
		else{
				glBindTexture(GL_TEXTURE_2D, img6);
				width = 1.2;
				cord1x=0,cord1y=0,cord2x=1,cord2y=0,cord3x=1.2,cord3y=1,cord4x=0.2,cord4y=1;
				glColor3ub(255,255,255);
		}
	 
		Dino::DrawDino(Point::Point(4,-0.8,0), width, 1 ,Point::Point(cord1x,cord1y,0), Point::Point(cord2x,cord2y,0), Point::Point(cord3x,cord3y,0), Point::Point(cord4x,cord4y,0));
		
		glPopMatrix();}
		
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
