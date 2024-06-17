#include "StudentHealthSate.h"
StudentHealthSate* StudentHealthSate::g_taskQ = nullptr;
std::mutex StudentHealthSate::g_mutex;

StudentHealthSate* StudentHealthSate::getInstance()
{
    if (g_taskQ == nullptr){
        g_mutex.lock();
        if (g_taskQ == nullptr){
           g_taskQ = new StudentHealthSate;
        }
        g_mutex.unlock();
    }
    return g_taskQ;
}
void StudentHealthSate::TestFunction(){
    qDebug()<<"测试成功......\n";
}
