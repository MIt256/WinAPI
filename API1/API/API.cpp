
#include <windows.h>
//if ERROR with MAIN: Linker-> system-> SubSystem (Choose Windows...) in Project settings

LRESULT CALLBACK MyWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (uMsg == WM_DESTROY)
	{
		PostQuitMessage(0);
	}
	//before WinMain (for win class initialization) (1)
//reaction on all events
//DefWindowProc your own processes
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
int WINAPI WinMain(	HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR lpCmdLine,int nCmdShow){
	
	//information about all param. in Onoshko program (from GoogleDrive)
	//simple windows creating
/*
		  //MB(window discriptor,output text,win name,buttons? | icon? )
	MessageBox(0, L"Hello,world!",L"project API", MB_OK | MB_ICONWARNING);//create simple window with button "OK"	

	int response =MessageBox(0, L"Hello,world? OR NOT?", L"1NAME", MB_YESNO | MB_ICONQUESTION);//create simple window with buttons "YES" & "NO"
	if (response == IDYES) {
		MessageBox(0, L"HORRAY", L"2NAME", MB_OK | MB_ICONINFORMATION);
	}

*/

//	Second part:
	//Window is a main GUI element
	//All windows refers to any Window Class
	//GUI applications in Windows is events-oriented (processes events)
	//interrupt --> create masseges 
	//in Windows: creates masseges queue, for all flows
	//GetMassage,PeekMassage - selecting from queue
	//creating massage(2)
	//DispatchMessage trunsfer fo the window proc.

	    // ATOM RegisterClassEx(CONST WNDCLASSEX * lpWindowClass);  //window class registration, for you unique window
	//Window class has many param. ~12+ (affect on window visual part)

	//(1):
	//win class initialization
		WNDCLASSEX wcex;
		HWND hWind;
		MSG msg;//(2)

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = 0;
		wcex.lpfnWndProc = MyWindowProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = 0;
		wcex.hCursor = LoadCursor(0, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = L"MyWindowClass";
		wcex.hIconSm = 0;
		RegisterClassEx(&wcex);//broadcast

	//crating window ~12 param. ;(
		CreateWindowEx(0, L"MyWindowClass", L"Randomtext", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 400, 300, 0, 0, hInstance, NULL);
	
	//(2):
		while (GetMessage(&msg, 0, 0, 0))//return true/false
		{
			DispatchMessage(&msg);
		}
return msg.wParam;
}

