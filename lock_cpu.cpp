// lock_cpu.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <windows.h>
#include <time.h>
#include <thread>

static HANDLE handle = 0;
static int end_f = 0;
static int i = 0;
static int mode = 3;
DWORD WINAPI  high_load(LPVOID id) {
    for (i= 0; end_f == 0; i++);
    return 0;
}
void normal_th() {
    for (i = 0; end_f == 0; i++);
}
int main()
{
    if (mode == 0) {
        handle = CreateThread(0, 0, &high_load, 0, 0, 0);
        SetThreadAffinityMask(handle, 1 << 0);
    }
    else if(mode==1) {
        handle = CreateThread(0, 0, &high_load, 0, 0, 0);
    }
    else if (mode == 2) {
        std::thread th_1(normal_th);
        SetThreadAffinityMask(th_1.native_handle(), 1 << 0);
        th_1.detach();
    }
    else if (mode == 3) {
        std::thread th_2(normal_th);
        th_2.detach();
    }else {
        std::cout << "Please set valid mode." << std::endl;
    }
    Sleep(30000);//WaitForSingleObject(handle[0], INFINITE);
    end_f = 1;
    Sleep(1);
    printf("%d", i);
    //Benched for 30sec.
    //lock thread to core:    267161689
    //lock free thread:       822861222
    //lock std:thread to core:363581241
    //lock free std:thread:   894167643
}