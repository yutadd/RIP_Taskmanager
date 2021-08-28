// lock_cpu.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <windows.h>
#include <time.h>
#include <thread>

static HANDLE handle = 0;
static int end_f = 0;
static int i = 0;
static int mode = 1;
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
        handle = CreateThread(0, 0, &high_load, 0, 0, 0);     //      スレッドを作成
        SetThreadAffinityMask(handle, 1 << 0);
    }
    else {
        std::thread th_1(normal_th);
        th_1.detach();
    }
    Sleep(30000);//WaitForSingleObject(handle[0], INFINITE);
    end_f = 1;
    Sleep(1);
    printf("%d", i);
    //Benched for 30sec.
    //lock core:  665382469
    //std::thread:785078786
}