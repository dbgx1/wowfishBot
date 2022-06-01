#pragma once
#include <vector>
#include "gameObject.h"

#include <QThread>
class context : public QThread {
public:
    std::vector<gameObject*> m_gameObjArray;
    dm::Dmsoft* m_dm = 0;
    long m_hwnd = 0;
    unsigned long long m_wowclassic_exe = 0;
    unsigned int m_runningtime = 0;
    QString m_state;

public:
    context(long hwnd);
    void InitGameObjectArray();
    void cleanGameObjectArray();
    gameObject characterObj();
    gameObject fishObj();
    bool fishIsHooked(gameObject& yp);
    void FinishFish(gameObject& yp);
    void fzl();
    void run();
};
