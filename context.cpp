#include "context.h"
#include "baseData.h"
#include <QDebug>
#pragma execution_character_set("utf-8")
context::context(long hwnd)
{
    m_hwnd = hwnd;
    m_dm = dm::Dmsoft::createObject();
    m_dm->setHwnd(hwnd);
    m_wowclassic_exe = m_dm->GetModuleBaseAddr(m_dm->m_hwnd, L"wowclassic.exe");
    if (m_wowclassic_exe == 0) {
    }
}

void context::InitGameObjectArray()
{
    cleanGameObjectArray();
    unsigned long long wowclassic = m_dm->GetModuleBaseAddr(m_dm->m_hwnd, L"wowclassic.exe");
    unsigned long long size = m_dm->QWORD(L"[%llx]", wowclassic + RVA_GAMEBASE);
    unsigned long long begin = m_dm->QWORD(L"[%llx]+%x", wowclassic + RVA_GAMEBASE, 0x8);

    int sum = 0;
    for (unsigned long long i = 0; i < size; i++)
    {
       
        unsigned long long arrayAdd = m_dm->QWORD(begin + i * 8);
        if (arrayAdd)
        {
          
            while (arrayAdd)
            {
                sum++;
                gameObject* p = new gameObject(m_dm, arrayAdd);
                p->printGameObj();
                m_gameObjArray.push_back(p);
                arrayAdd = m_dm->QWORD(arrayAdd);
            }


        }
    }
}

void context::cleanGameObjectArray()
{
    for (auto v : m_gameObjArray)
    {
        delete v;
    }
    m_gameObjArray.clear();
}

gameObject context::characterObj()
{
    InitGameObjectArray();
    for (auto v : m_gameObjArray)
    {
        if (v->m_type == 7)
        {
            return *v;
         }
    }
    return gameObject();
}

gameObject context::fishObj()
{
    InitGameObjectArray();
    gameObject zj = characterObj();
    for (auto v : m_gameObjArray) {

        if (v->m_type == 8 && v->getName() == L"鱼漂" && (zj.m_id.id1 == v->m_suoShuId.id1 && zj.m_id.id2 == v->m_suoShuId.id2)) {
            return *v;
        }
    }
    return gameObject();
}

bool context::fishIsHooked(gameObject& yp)
{
    unsigned int b = m_dm->DWORD(yp.m_obj + FISHISHOOKEN);
    if (b == 0x40001) {
        m_state = "鱼上钩";
        return true;
    }
    return false;
}

void context::FinishFish(gameObject& yp)
{
    m_state = "收杆";
    m_dm->AsmClear();
    m_dm->AsmAdd(L"push rax");
    m_dm->AsmAdd(L"push rbx");
    m_dm->AsmAdd(L"push rcx");
    m_dm->AsmAdd(L"push rdx");
    m_dm->AsmAdd(L"mov rcx,%llx", yp.m_obj);
    m_dm->AsmAdd(L"mov rax,%llx", m_wowclassic_exe + CALL_FinishFish);
    m_dm->AsmAdd(L"sub rsp,380");
    m_dm->AsmAdd(L"call rax");
    m_dm->AsmAdd(L"add rsp,380");
    m_dm->AsmAdd(L"pop rdx");
    m_dm->AsmAdd(L"pop rcx");
    m_dm->AsmAdd(L"pop rbx");
    m_dm->AsmAdd(L"pop rax");
    m_dm->AsmCall(m_dm->m_hwnd, 6);
    Sleep(1000);
    fzl();
}

void context::fzl()
{
    if ((GetTickCount() - m_runningtime )> 30 * 1000)
    {
        m_dm->SetWindowState(m_dm->m_hwnd, 1);
        Sleep(100);
        m_dm->KeyPress(32);
        m_runningtime = GetTickCount();
   }
}

void context::run()
{
    m_state = "准备运行";
    m_runningtime = GetTickCount();
    while (true)
    {
        gameObject yp = fishObj();

        if (yp.m_obj == 0)
        {
            m_state = "抛竿";
            m_dm->SetWindowState(m_dm->m_hwnd , 1);
            m_dm->KeyPress(49);
            Sleep(1000);
        } else {
            m_state = "等待上鱼";
        }

        if (fishIsHooked(yp))
        {
            FinishFish(yp);
        }
    }

    
}
