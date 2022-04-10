#include <windows.h>
#include <TCHAR.H>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	HWND 	 hwnd;
	MSG 	 msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = _T("Window Class Name");
	RegisterClass(&WndClass);
	hwnd = CreateWindow(_T("Window Class Name"),
		_T("Window Title Name"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		300,
		400,
		NULL,
		NULL,
		hInstance,
		NULL
		);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT ps;
	RECT rect;
	HBRUSH hBrush;

	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		Rectangle(hdc, rect.left = 100, rect.top = 0, rect.right = 150, rect.bottom = 100);
		DrawText(hdc, _T("위쪽"), _tcslen(_T("위쪽")), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		Rectangle(hdc, rect.left = 50, rect.top = 100, rect.right = 100, rect.bottom = 200);
		DrawText(hdc, _T("왼쪽"), _tcslen(_T("왼쪽")), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		Rectangle(hdc, rect.left = 150, rect.top = 100, rect.right = 200, rect.bottom = 200);
		DrawText(hdc, _T("오른쪽"), _tcslen(_T("오른쪽")), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		Rectangle(hdc, rect.left = 100, rect.top = 200, rect.right = 150, rect.bottom = 300);
		DrawText(hdc, _T("아래쪽"), _tcslen(_T("아래쪽")), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);
		break;
	case WM_KEYDOWN:
		hdc = GetDC(hwnd);
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		(HBRUSH)SelectObject(hdc, hBrush);

		if (wParam == VK_UP){
			Rectangle(hdc, 100, 0, 150, 100);
		}
		else if (wParam == VK_LEFT){
			Rectangle(hdc, 50, 100, 100, 200);
		}
		else if (wParam == VK_RIGHT){
			Rectangle(hdc, rect.left = 150, 100, 200, 200);
		}
		else if (wParam == VK_DOWN){
			Rectangle(hdc, 100, 200, 150, 300);
		}

		DeleteObject(hBrush);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_KEYUP:
		InvalidateRgn(hwnd, NULL, TRUE);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}