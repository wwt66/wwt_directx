#pragma once
#include <DirectXMath.h>
#include <d3d11_1.h>
#include <string>
class GameApp 
{
public:
	GameApp(HINSTANCE hInstance, int width, int height, std::wstring windowName);
	bool Init();
	int Run();
	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
private:
	bool InitD3D();
	//bool InitEffect();
	//bool InitResource();
	//void OnResize();

	HINSTANCE m_hInstance;
	HWND m_hMainWnd;
	std::wstring m_strMainWndCaption;
	int m_nWidth;
	int m_nHeight;

};