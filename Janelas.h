#pragma once

#include "framework.h"

typedef struct {
    COLORREF titleText;
    COLORREF titleBg;
} CustomColors;

// Função de callback da janela principal
BOOL CALLBACK JanelaMain(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_INITDIALOG:

        // Mudar o texto da barra de título
        SetWindowText(hwnd, "ASM 8000");
        return TRUE;
        break;

    case WM_CTLCOLORDLG: 
        static HBRUSH hBrush = CreateSolidBrush(RGB(240, 240, 240));
        return (INT_PTR)hBrush;
        break;

    case WM_COMMAND:
        // Tratamento de comandos (botões, menus, etc.)
        switch (LOWORD(wParam)) {}
        break;

    case WM_CLOSE:
        // Fechar a janela
        DestroyWindow(hwnd);
        break;

    case WM_DESTROY:
        // Encerrar a aplicação
        PostQuitMessage(0);
        break;

    default:
        return FALSE;
    }
    return TRUE;
}



