#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <windows.h> 
#include<cmath>
#define ID_EDITCHILD 100
#include<string>
#include <stdlib.h>

HWND hWnda, hWnda1;
HFONT hFont, hFont1;
char buff1[20], buff2[20];
LPCSTR buf1 = "\0";
char buff[128], binn[128], factb[128];
std::string buffer1, buffer2, str, str1;
bool bin = false, orr = false, xxor = false, nott = false, annd = false, binar = false, point = false, shiftl = false, shiftr = false;
bool sign = false, min = false, mul = false, divis = false, add = false, eq = false, sign1 = false, proc = false, fact = false, integer = false;
void Calc(double sum1, double sum2);
void OneOperation(double sum1);
void Booling(int sum1, int sum2);
void Nott(int sum1);
void Breakable(int sum1);
void Binnar(int sum1);
void Fact(int sum1);

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	double sum1 = 0, sum2 = 0;
	bool minus = false;
	HDC hdc;
	PAINTSTRUCT ps;
	std::string number1, number2;
	switch (msg) {
	case WM_CREATE:
	{
		HWND button7 = CreateWindow("button", "7", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 150, 100, 50, hWnd, (HMENU)10007, nullptr, nullptr);
		HWND button4 = CreateWindow("button", "4", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 200, 100, 50, hWnd, (HMENU)10004, nullptr, nullptr);
		HWND button1 = CreateWindow("button", "1", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 250, 100, 50, hWnd, (HMENU)10001, nullptr, nullptr);
		HWND button2 = CreateWindow("button", "2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 250, 100, 50, hWnd, (HMENU)10002, nullptr, nullptr);
		HWND button5 = CreateWindow("button", "5", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 200, 100, 50, hWnd, (HMENU)10005, nullptr, nullptr);
		HWND button8 = CreateWindow("button", "8", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 150, 100, 50, hWnd, (HMENU)10008, nullptr, nullptr);
		HWND button3 = CreateWindow("button", "3", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 250, 100, 50, hWnd, (HMENU)10003, nullptr, nullptr);
		HWND button6 = CreateWindow("button", "6", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 200, 100, 50, hWnd, (HMENU)10006, nullptr, nullptr);
		HWND button9 = CreateWindow("button", "9", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 150, 100, 50, hWnd, (HMENU)10009, nullptr, nullptr);
		HWND button0 = CreateWindow("button", "0", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			00, 300, 200, 50, hWnd, (HMENU)10000, nullptr, nullptr);
		HWND buttonp = CreateWindow("button", ".", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 300, 100, 50, hWnd, (HMENU)10011, nullptr, nullptr);
		HWND buttone = CreateWindow("button", "=", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 300, 100, 50, hWnd, (HMENU)10012, nullptr, nullptr);
		HWND buttona = CreateWindow("button", "+", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 250, 100, 50, hWnd, (HMENU)10013, nullptr, nullptr);
		HWND buttons = CreateWindow("button", "-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 200, 100, 50, hWnd, (HMENU)10014, nullptr, nullptr);
		HWND buttonm = CreateWindow("button", "*", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 150, 100, 50, hWnd, (HMENU)10015, nullptr, nullptr);
		HWND buttond = CreateWindow("button", "/", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 100, 100, 50, hWnd, (HMENU)10016, nullptr, nullptr);
		HWND buttonproc = CreateWindow("button", "%", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 100, 100, 50, hWnd, (HMENU)10017, nullptr, nullptr);
		HWND buttonchan = CreateWindow("button", "+/-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 100, 100, 50, hWnd, (HMENU)10018, nullptr, nullptr);
		HWND buttonerr = CreateWindow("button", "C", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 100, 100, 50, hWnd, (HMENU)10019, nullptr, nullptr);
		HWND buttonbin = CreateWindow("button", "Bin", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 100, 100, 50, hWnd, (HMENU)10020, nullptr, nullptr);
		HWND buttonor = CreateWindow("button", "OR", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 150, 100, 50, hWnd, (HMENU)10021, nullptr, nullptr);
		HWND buttonand = CreateWindow("button", "AND", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 200, 100, 50, hWnd, (HMENU)10022, nullptr, nullptr);
		HWND buttonxor = CreateWindow("button", "XOR", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 250, 100, 50, hWnd, (HMENU)10023, nullptr, nullptr);
		HWND buttonnot = CreateWindow("button", "NOT", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 300, 100, 50, hWnd, (HMENU)10024, nullptr, nullptr);
		HWND buttonshiftl = CreateWindow("button", ">>", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			500, 300, 100, 50, hWnd, (HMENU)10025, nullptr, nullptr);
		HWND buttonshiftr= CreateWindow("button", "<<", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			500, 250, 100, 50, hWnd, (HMENU)10026, nullptr, nullptr);
		HWND buttonfact = CreateWindow("button", "!", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			500, 200, 100, 50, hWnd, (HMENU)10027, nullptr, nullptr);
		hWnda = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("STATIC"), buf1, WS_CHILD | WS_VISIBLE | SS_RIGHT, 0, 37, 600, 65, hWnd, HMENU(nullptr), GetModuleHandle(nullptr), nullptr);
		hWnda1 = CreateWindowEx(0, TEXT("EDIT"), nullptr, WS_CHILD | WS_VISIBLE | SS_RIGHT, 40, 0, 560, 37, hWnd, (HMENU) ID_EDITCHILD, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), nullptr);
		//boling = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("STATIC"), num, WS_CHILD | WS_VISIBLE | SS_RIGHT, 0, 388, 400, 20, hWnd, HMENU(nullptr), GetModuleHandle(nullptr), nullptr);
		hFont = CreateFontA(50, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
		hFont1 = CreateFontA(30, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
		SendMessage(hWnda, WM_SETFONT, WPARAM(hFont), TRUE);
		SendMessage(hWnda1, WM_SETFONT, WPARAM(hFont1), TRUE);
		ShowWindow(hWnda, 255);

		return 0;
	}
	case WM_DESTROY: 
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case 10000: {
			buf1 = "0";
			break;
		}
		case 10001: {
			buf1 = "1";
			break;
		}
		case 10002: {
			buf1 = "2";
			break;
		}
		case 10003: {
			buf1 = "3";
			break;
		}
		case 10004: {
			buf1 = "4";
			break;
		}
		case 10005: {
			buf1 = "5";
			break;
		}
		case 10006: {
			buf1 = "6";
			break;
		}
		case 10007: {
			buf1 = "7";
			break;
		}
		case 10008: {
			buf1 = "8";
			break;
		}
		case 10009: {
			buf1 = "9";
			break;
		}
		case 10011: {
			buf1 = ".";
			point = true;
			break;
		}
		case 10012:
		{
			sign = false;
			buffer2 = buff2;
			if (integer)
			{
				if(point)
				{
					MessageBox(hWnda, "Binar cannot be double", "Error", MB_OK);
				}
				sum1 = atoi(buffer1.c_str());
				sum2 = atoi(buffer2.c_str());
				Booling(sum1, sum2);
			}
			else
			{
				sum1 = atof(buffer1.c_str());
				sum2 = atof(buffer2.c_str());
			}
			strcpy_s(buff2, "\0");
			buf1 = "\0";
			//if (sign1) {
			//	Binnar(sum1);
			//	Fact(sum1);
			//	Breakable(sum1);
			//	OneOperation(sum1);
			//	sign1 = false;
			//}
			Calc(sum1, sum2);
			str = buff;
			strcpy_s(buff, "\0");
			SetWindowTextA(hWnda1, str.c_str());
			integer = false;
			point = false;
			break;
		}
		case 10013: {
			sign = true;
			add = true;
			//eq = sum1 + sum2;
			break;
		}
		case 10014: {
			sign = true;
			min = true;
			//eq = sum1 - sum2;
			break;
		}
		case 10015: {
			sign = true;
			mul = true;
			//eq = sum1 * sum2;
			break;
		}
		case 10016: {
			sign = true;
			divis = true;
			//eq = sum1 / sum2;
			break;
		}
		case 10017: {
			sign1 = true;
			proc = true;
			break;
		}
		case 10018:
			minus = true;
			//buf1 = "-";
			break;
		case 10019:
		{
			buf1 = "\0";
			strcpy_s(buff1, "");
			strcpy_s(buff2, "\0");
			SetWindowTextA(hWnda1, "");
			break;
		}
		case 10020:
			{
			integer = true;
			bin = true;
			sign1 = true;
			}
		case 10021:
		{
			integer = true;
			orr = true;
			sign = true;
		}
		case 10022:
		{
			integer = true;
			annd = true;
			sign = true;
		}
		case 10023:
		{
			integer = true;
			xxor = true;
			sign = true;
		}
		case 10024:
		{
			integer = true;
			nott = true;
			sign1 = true;
		}
		case 10025:
		{
			integer = true;
			sign = true;
			shiftl = true;
		}
		case 10026:
		{
			integer = true;
			sign = true;
			shiftr = true;
		}
		case 10027:
		{
			integer = true;
			sign1 = true;
			fact = true;
		}
		}
		if(!sign)
		{
				strcat_s(buff1, sizeof(buff1), buf1);
				SetWindowText(hWnda, buff1);
				buf1 = "\0";
				buffer1 = buff1;
		}
		if (sign) {
			strcpy_s(buff1, "\0");
			strcat_s(buff2, sizeof(buff2), buf1);
			SetWindowText(hWnda, buff2);
		}
		if (sign1)
		{
			strcpy_s(buff1, "\0");
		}
		return 0;
	}
	case WM_PAINT: 
	{
		hdc = BeginPaint(hWnd, &ps);
		HFONT hfont = CreateFont(25, 10, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, "Font");
		SelectObject(hdc, hfont);
		//TextOut(hdc, 0, 0, buf1, sizeof(buf1));
		DeleteObject(hfont);
	}
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}
int WINAPI WinMain(HINSTANCE hInst,	
	HINSTANCE hPrev,		
	LPSTR szCmdLine,	
	int nShowCmd)			
{
	WNDCLASSEX wcx = { 0 };
	wcx.cbSize = sizeof(WNDCLASSEX); 
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = WndProc;
	wcx.hInstance = hInst;	
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 
	wcx.lpszClassName = "Calculator";
	if (!RegisterClassEx(&wcx))
		return 1;
	HWND hWnd = CreateWindowEx(0,
		"Calculator",
		"Calculator",
		WS_OVERLAPPEDWINDOW | WS_OVERLAPPED|WS_SYSMENU|WS_BORDER,
		CW_USEDEFAULT, 0,
		CW_USEDEFAULT, 0,
		nullptr, 
		nullptr,
		hInst,
		nullptr);
	SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 615 /*width*/, 388 /*height*/, SWP_NOMOVE);
		if (!hWnd)   
			return 2;
		ShowWindow(hWnd, nShowCmd);
		UpdateWindow(hWnd);
	//HWND hWndChild = CreateWindowEx(0, "ChildWClass", (LPCTSTR)nullptr, WS_CHILD | WS_BORDER,
	//		0, 0, 0, 0, hWnd, (HMENU)100, hInst, nullptr);
	//SetWindowPos(hWndChild, HWND_BOTTOM, 0, 0, 315 /*width*/, 288 /*height*/, SWP_NOMOVE);
	//if (!hWndChild)
	//	return 2;
	//ShowWindow(hWndChild, nShowCmd);
	//UpdateWindow(hWndChild);
	MSG msg = { nullptr };
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

void Calc(double sum1, double sum2)
{
	double eq = 0;
	if (min)
	{
		eq = sum1 - sum2;
		min = false;
		sprintf_s(buff, "%lf", eq);
	}
	if (divis)
	{
		if(sum2 == 0)
			MessageBox(hWnda, "Cannot divide by zero", "Error", MB_OK);
		else {
			eq = sum1 / sum2;
			sprintf_s(buff, "%lf", eq);
		}
		divis = false;
	}
	if (mul)
	{
		eq = sum1 * sum2;
		sprintf_s(buff, "%lf", eq);
		mul = false;
	}
	if (add)
	{
		eq = sum1 + sum2;
		sprintf_s(buff, "%0.5lf", eq);
		//str = std::to_string(eq);
		add = false;
	}
}
void OneOperation(double sum1)
{
	double eq = 0;
	int k = 0;
	if(proc)
	{
		eq = sum1 / 100;
		sprintf_s(buff, "%0.5lf", eq);
		proc = false;
	}
}

void Booling(int sum1, int sum2)
{
	int eq;
	if (orr)
	{
		eq = sum1 | sum2;
		sprintf_s(buff, "%d", eq);
		orr = false;
	}
	if (xxor)
	{
		eq = sum1 ^ sum2;
		sprintf_s(buff, "%d", eq);
		xxor = false;
	}
	if (annd)
	{
		eq = sum1 & sum2;
		sprintf_s(buff, "%d", eq);
		annd = false;
	}
	if(shiftr)
	{
		eq = sum1 << sum2;
		sprintf_s(buff, "%d", eq);
		shiftr = false;
	}
	if(shiftl)
	{
		eq = sum1 >> sum2;
		sprintf_s(buff, "%d", eq);
		shiftl = false;
	}
}

void Breakable(int sum1)
{
	if (nott)
	{
		int s;
		s = ~sum1;
		sprintf_s(buff, "%d", s);
		nott = false;
	}
}
void Binnar(int sum1)
{
	if (bin) {
		_itoa_s(sum1, buff, 2);
		bin = false;
	}
}

void Fact(int sum1)
{
	if (fact) {
		int k = 1;
		if (sum1 == 0)
		{
			sprintf_s(factb, "%d", k);
		}
		else if (sum1 > 0)
		{
			while (sum1)
			{
				k *= sum1;
				sum1--;
			}
			sprintf_s(factb, "%d", k);
		}
		str1 = factb;
		fact = false;
		SetWindowTextA(hWnda1, str1.c_str());
	}
}