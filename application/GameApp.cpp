#include "GameApp.h"

namespace
{
	GameApp* g_pGameApp = nullptr;
}


GameApp::GameApp(HINSTANCE hInstance, int width, int height, std::wstring windowName) :
	m_hInstance(hInstance),
	m_nWidth(width),
	m_nHeight(height),
	m_strMainWndCaption(windowName)
{
	g_pGameApp = this;
}

bool GameApp::Init()
{
	if (!InitD3D()) 
		return false;
	//if (!InitEffect())
	//	return false;
	//if (!InitResource())
	//	return false;
	return true;
}

int GameApp::Run()
{
	MSG msg{ 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			Sleep(1000);
		}
	}
	return (int)msg.wParam;
}

LRESULT GameApp::MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        // WM_ACTIVATE is sent when the window is activated or deactivated.  
        // We pause the game when the window is deactivated and unpause it 
        // when it becomes active.  
    case WM_ACTIVATE:
        if (LOWORD(wParam) == WA_INACTIVE)
        {
        }
        else
        {
        }
        return 0;

        // WM_SIZE is sent when the user resizes the window.  
    case WM_SIZE:
       
        return 0;

        // WM_EXITSIZEMOVE is sent when the user grabs the resize bars.
    case WM_ENTERSIZEMOVE:
      
        return 0;

        // WM_EXITSIZEMOVE is sent when the user releases the resize bars.
        // Here we reset everything based on the new window dimensions.
    case WM_EXITSIZEMOVE:
      
        return 0;

        // WM_DESTROY is sent when the window is being destroyed.
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

        // The WM_MENUCHAR message is sent when a menu is active and the user presses 
        // a key that does not correspond to any mnemonic or accelerator key. 
    case WM_MENUCHAR:
        // Don't beep when we alt-enter.
        return MAKELRESULT(0, MNC_CLOSE);

        // Catch this message so to prevent the window from becoming too small.
    case WM_GETMINMAXINFO:
        ((MINMAXINFO*)lParam)->ptMinTrackSize.x = 200;
        ((MINMAXINFO*)lParam)->ptMinTrackSize.y = 200;
        return 0;

    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
        return 0;
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
        return 0;
    case WM_MOUSEMOVE:
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}


LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
	return g_pGameApp->MsgProc(hwnd, msg, wParam, lParam);
}

bool GameApp::InitD3D()
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = MainWndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hInstance;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"D3DWndClassName";

	if (!RegisterClass(&wc)) {
		MessageBox(0, L"注册窗口类失败", 0, 0);
		return false;
	}
	RECT R = { 0, 0, m_nWidth, m_nHeight };
	AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
	m_nWidth = R.right - R.left;
	m_nHeight = R.bottom - R.top;

	m_hMainWnd = CreateWindow(L"D3DWndClassName", m_strMainWndCaption.c_str(),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, m_nWidth, m_nHeight, 0, 0, m_hInstance, 0);
	if (!m_hMainWnd)
	{
		MessageBox(0, L"创建窗口失败", 0, 0);
		return false;
	}

	ShowWindow(m_hMainWnd, SW_SHOW);
	UpdateWindow(m_hMainWnd);
	return true;
}
