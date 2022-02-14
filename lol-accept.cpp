#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "D:\Programming\C trenovani\headers\colors.h"
#include <iostream>

int main()
{
    int width;
    int height;

    int red = 0;
    int green = 0;
    int blue = 0;

    int loop = 0;

    HWND hwnd;
    if (hwnd = FindWindowA(NULL, "League of Legends"))
    {
        set_color("green");
        printf("League found!\n");
        set_color("default");
    }
    else {
        set_color("red");
        printf("Searching for League...\n");
        set_color("default");

        while (hwnd == NULL)
        {
            hwnd = FindWindowA(NULL, "League of Legends");
            Sleep(500);
        }
        set_color("green");
        printf("League found!\n");
        set_color("default");

    }
    RECT rect;
    RECT screen;
    HWND hdesktop = GetDesktopWindow();
    GetWindowRect(hdesktop, &screen);
    if (GetWindowRect(hwnd, &rect))
    {
        width = rect.right - rect.left;
        height = rect.bottom - rect.top;
    }
#if _DEBUG
    set_color("purple");
    printf("League found => width - %d ; height - %d\n", width, height);
    set_color("default");
#endif    
    while (loop == 0)
    {
        if (GetKeyState(VK_ESCAPE) & 0x8000)
        {
            loop = 1;
        }
    
        while (red != 30 && green != 37 && blue != 42)
        {

            if (GetKeyState(VK_ESCAPE) & 0x8000)
            {
                loop = 1;
                break;
            }

            HDC dc = GetDC(hwnd);
            COLORREF color = GetPixel(dc, 870, 690);
            ReleaseDC(hwnd, dc);
            red = GetRValue(color);
            green = GetGValue(color);
            blue = GetBValue(color);
            Sleep(500);
        }
        Sleep(500);
        set_color("cyan");
        printf("Match Found!\n");
        set_color("default");
        INPUT Inputs[3] = { 0 };

        RECT lolko;

        GetWindowRect(hwnd, &lolko);
        MapWindowPoints(hdesktop, GetParent(hwnd), (LPPOINT)&lolko, 2);


        int horizontal = lolko.left + width - 797;
        int vertical = lolko.top + height - 214;

        SetCursorPos(horizontal, vertical);
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 100, 100);
        Sleep(100);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 200, 200);

        red = 0;
        green = 0;
        blue = 0;

        Sleep(15000);
    }


    return 0;
}