#include <Windows.h>
#include <iostream>
#include <vector>
#include <dxgi.h>
#include <d3d11.h>

#include "../PCBuildingsSimulator2Cheat/Dependencies/Kiero/kiero.h" //Kiero :D

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;