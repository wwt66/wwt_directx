
#include <Windows.h>
#include "GameApp.h"
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE prevInstance,
    _In_ LPSTR cmdLine, _In_ int showCmd) {
    UNREFERENCED_PARAMETER(prevInstance);
    UNREFERENCED_PARAMETER(cmdLine);
    UNREFERENCED_PARAMETER(showCmd);

    GameApp app(hInstance, 1280, 720, L"wwt_directx");
    if (!app.Init())
        return -1;
    return app.Run();
}