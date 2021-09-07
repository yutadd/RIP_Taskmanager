// lock_cpu.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#include <windows.h>
#include <thread>
static int end_f[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
DWORD WINAPI  high_load(LPVOID id) {
    while (true) {
        while(end_f[(int)id] == 0);
        Sleep(16);
    }
    return 0;
}
int main()
{
    HANDLE handle = 0;
    int ia = 0;
        for (ia = 0; ia < 16; ia++) {
            handle = CreateThread(0,0,&high_load,(LPVOID)(ia),0,0);
            SetThreadAffinityMask(handle, 1 << (ia));
            end_f[(ia)] = 0;
        }
        while (true) {
            Sleep(310);
            for (ia = 0; ia < 16; ia++) {
                end_f[ia] = 1;
            }
            Sleep(520);
            for (ia = 0; ia < 16; ia++) {
                end_f[ia] = 0;
            }
        }
    //Sleep(1);
    //printf("%d", i);
    //Benched for 30sec.
    //lock thread to core:    267161689
    //lock free thread:       822861222
    //lock std:thread to core:363581241
    //lock free std:thread:   894167643
}