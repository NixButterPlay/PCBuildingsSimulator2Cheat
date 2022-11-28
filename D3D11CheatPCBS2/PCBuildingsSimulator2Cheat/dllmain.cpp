// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h> //Windows Include :D
#include "../PCBuildingsSimulator2Cheat/Dependencies/PCBS2SDK/PCBS2SDK.hpp"
#include "../PCBuildingsSimulator2Cheat/Dependencies/Il2CppResolve/Includes.hpp"
#include "../PCBuildingsSimulator2Cheat/Dependencies/Il2CppResolve/Main.hpp"
#include "ImguiIncludes.h" //Imgui Includes for Init Cheat Window :D
#include "main.h" //Main Includes :D
#include "Dependencies/Imgui/imgui_impl_win32.h"
#define RET_TRUE return true; //Returning TRUE :D
#define TRUE_RET return TRUE;
#define FALSE_RET return FALSE;
#define RET_FALSE return false;

Present oPres;
WNDPROC oWndProc;
HWND window = NULL; //HWND Window to Initialization Cheat Window :D
bool init = false;
bool openmenu = true;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
void InitImgui()
{
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 20, NULL, io.Fonts->GetGlyphRangesCyrillic());
    io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
    ImGui_ImplWin32_Init(window);
    ImGui_ImplDX11_Init(pDevice, pContext);
}
LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
        return true;

    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags, HMODULE hMod) {
    ID3D11RenderTargetView* mainRenderTargetView;
    if (InitIl2Cpp()) {
        std::cout << "Il2Cpp Has Been Established" << std::endl;
    }
    else
    {
        TerminateProcess(GetCurrentProcess(), 2154);
    }
    if (!init) 
    {
        if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice))) 
        {
            pDevice->GetImmediateContext(&pContext);
            DXGI_SWAP_CHAIN_DESC sd;
            pSwapChain->GetDesc(&sd);
            window = sd.OutputWindow;
            ID3D11Texture2D* pBackBuffer;
            pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
            pDevice->CreateRenderTargetView(0, NULL, &mainRenderTargetView);
            pBackBuffer->Release();
            oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
            InitImgui();
            init = true;
        }
    }
    else 
    {
        return oPres(pSwapChain, SyncInterval, Flags); //Returning stdcall Present :D
    }
    auto flags = ImGuiConfigFlags_NoMouseCursorChange | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;
    if (GetAsyncKeyState(VK_INSERT)) 
    {
        openmenu = !openmenu;
    }
    if (GetAsyncKeyState(VK_END)) 
    {
        kiero::shutdown(); //Shutdown Kiero!!! :D
    }
    if (openmenu) {

        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("PCBS2Cheat by NixButterPlay", nullptr, flags); //Imgui Begin :D

        if (ImGui::Button("Set Unlimited Money", ImVec2(100.F, 25.F))) 
        {
            SetMoney(200000);
        }
        ImGui::End();
        ImGui::Render();

        pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    }
}




bool OpenConsole() {
    //Soon...
    RET_TRUE;
}

bool CloseConsole() {
    //Soon...
    RET_TRUE;
 }

DWORD WINAPI InitPCBS2Cheat() {
    bool init_cheat = false;
    do 
    {
        if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
            kiero::bind(8, (void**)&oPres, hkPresent);
            init_cheat = true;
        }
        else {
            while (true) 
            {
                Sleep(2000);
                Beep(500, 500);
            }
        }
    } while (!init_cheat);
    {
        TRUE_RET;
    }

}
 BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  dwReason,
                       LPVOID lpReserved
                     )
 {
        if (dwReason == DLL_PROCESS_ATTACH) {
            DisableThreadLibraryCalls(hModule);
            CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)InitPCBS2Cheat, hModule, 0, 0));
        }
        else {
            MessageBoxA(0, "Process Has Not Attached Successfull", "PCBS2Cheat", MB_OK);
        }
            return TRUE;

 }

