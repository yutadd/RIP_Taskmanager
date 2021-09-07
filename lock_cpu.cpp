// lock_cpu.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <windows.h>
#include <time.h>
#include <thread>

static HANDLE handle = 0;
static int end_f[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
static int i = 0;
static int mode = 3;
DWORD WINAPI  high_load(LPVOID id) {
    while (true) {
        for (i= 0; end_f[(int)id] == 0; i++);
        Sleep(16);
    }
    return 0;
}
void normal_th() {
    for (i = 0; end_f == 0; i++);
}
int main()
{
    while (true) {
        for (int i = 0; i < 16; i++) {
            handle = CreateThread(0, 0, &high_load, (LPVOID)(i), 0, 0);
            SetThreadAffinityMask(handle, 1 << (i));
            end_f[(i)] = 0;
        }
        Sleep(310);
        for (int i = 0; i < 16; i++) {
            end_f[i] = 1;
        }
        Sleep(520);
    }
    Sleep(40000);
    //Sleep(1);
    //printf("%d", i);
    //Benched for 30sec.
    //lock thread to core:    267161689
    //lock free thread:       822861222
    //lock std:thread to core:363581241
    //lock free std:thread:   894167643
}