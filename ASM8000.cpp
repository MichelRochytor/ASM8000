#include "framework.h"
#include "ASM8000.h"

HINSTANCE hInst;                                // Instância da aplicação

// Protótipo da função de callback da janela
BOOL CALLBACK JanelaMain(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Função principal da aplicação
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    hInst = hInstance;

    SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);
    // Cria a janela principal
    HWND hwnd1 = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)JanelaMain);
    if (hwnd1 == NULL) {
        MessageBox(NULL, "Falha ao criar a janela principal!", "Erro", MB_ICONERROR);
        return 1;
    }

    // Mostra a janela
    ShowWindow(hwnd1, nCmdShow);
    UpdateWindow(hwnd1);

    // Loop de mensagens
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
