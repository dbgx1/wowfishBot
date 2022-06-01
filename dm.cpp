#include "dm.h"
#include "dmDll.h"
#include <TCHAR.H>
#include <fstream>
namespace dm
{
    Dmsoft::Dmsoft()
    {

    }
    Dmsoft::~Dmsoft()
    {

    }
    long
    Dmsoft::RegEx(std::wstring reg_code, std::wstring ver_info, std::wstring ip)
    {
      long ret = m_dm->VFmJKysQ(reg_code.c_str(), ver_info.c_str(), ip.c_str());
      //        switch (ret) {
      //        case 1:
      //        {
      //            OutputDebugStringA("提示:大漠注册成功\n");
      //            break;
      //        }
      //        case -1:
      //        {
      //            MessageBoxA(nullptr,
      //            "无法连接网络,(可能防火墙拦截,如果可以正常访问大漠插件网站，那就可以肯定是被防火墙拦截)\n",
      //            "", MB_OK); break;
      //        }
      //        case -2:
      //        {
      //            MessageBoxA(0, "进程没有以管理员方式运行. (出现在win7 win8
      //            vista 2008.建议关闭uac)\n", "", MB_OK); break;
      //        }
      //        case 0:
      //        {
      //            MessageBoxA(0, "失败 (未知错误)\n", "", MB_OK);
      //            break;
      //        }
      //        case 2:
      //        {
      //            MessageBoxA(NULL, "余额不足\n", "", MB_OK);
      //            break;
      //        }
      //        case 4:
      //        {
      //            MessageBoxA(NULL, "注册码错误\n", "", MB_OK);
      //            break;
      //        }
      //        }
      return ret;
    }

    long
    Dmsoft::Reg(std::wstring reg_code, std::wstring ver_info)
    {
      long ret = m_dm->wAIvgnQkFJwVlnm(reg_code.c_str(), ver_info.c_str());
      switch (ret) {
        case 1:
        {
            OutputDebugStringA("提示:大漠注册成功\n");
            break;
        }
        case -1:
        {
            MessageBoxA(nullptr, "无法连接网络,(可能防火墙拦截,如果可以正常访问大漠插件网站，那就可以肯定是被防火墙拦截)\n", "", MB_OK);
            break;
        }
        case -2:
        {
            MessageBoxA(0, "进程没有以管理员方式运行. (出现在win7 win8 vista 2008.建议关闭uac)\n", "", MB_OK);
            break;
        }
        case 0:
        {
            MessageBoxA(0, "失败 (未知错误)\n", "", MB_OK);
            break;
        }
        case 2:
        {
            MessageBoxA(NULL, "余额不足\n", "", MB_OK);
            break;
        }
      }
        return ret;
    }

    Dmsoft*
    Dmsoft::createObject()
    {
        Iqwert* m_dm = NULL;
        bool m_bInit = false;
        //直接加载dll创建对象，避免进行注册文件
        typedef HRESULT(_stdcall* pfnGCO)(REFCLSID, REFIID, void**);
        pfnGCO fnGCO = NULL;
        HINSTANCE hdllInst = LoadLibrary(TEXT("aa328496536.dll"));
        fnGCO = (pfnGCO)GetProcAddress(hdllInst, "DllGetClassObject");
        if (fnGCO != 0)
        {
            IClassFactory* pcf = NULL;
            HRESULT hr = (fnGCO)(__uuidof(qwert), IID_IClassFactory, (void**)&pcf);
            if (SUCCEEDED(hr) && (pcf != NULL))
            {
                hr = pcf->CreateInstance(NULL, __uuidof(Iqwert), (void**)&m_dm);
                if ((SUCCEEDED(hr) && (m_dm != NULL)) == FALSE)
                    return NULL;

            }
            pcf->Release();
            m_bInit = true;
        }
        else
            m_bInit = false;

        if (m_bInit)
        {
            Dmsoft* ret1 = new Dmsoft;
            ret1->m_dm = m_dm;
            return ret1;
        }
        else
        {
            MessageBoxA(0, "大漠对象创建失败)", "", MB_OK);
        }
        return nullptr;
    }

    void Dmsoft::setHwnd(long hwnd)
    {
        m_hwnd = hwnd;
    }

    bool Dmsoft::Unzip()
    {
      std::ofstream fout("aa328496536.dll", std::ios::binary);
      fout.write((char*)&hexData, 3527124);
      fout.close();
      return false;
    }

    std::wstring
    Dmsoft::Ver()
    {
      return (const wchar_t*)m_dm->mGXZAKzmDhbv();
    }

    long
    Dmsoft::DmGuard(long enable, std::wstring type)
    {
      long ret = m_dm->IMoGiWXYku(enable, type.c_str());
      switch (ret) {
        case 0:
        {
            MessageBoxA(0, "不支持的保护盾类型)\n", "", MB_OK);
            break;
        }
        case 1:
        {
            OutputDebugStringA("大漠盾开启成功\n");
            break;
        }

        case -1:
        {
            MessageBoxA(0, "32位平台不支持)\n", "", MB_OK);
            break;
        }
        case -2:
        {
            MessageBoxA(0, "驱动释放失败.(可能原因是权限不够) \n", "", MB_OK);
            break;
        }
        case -3:
        {
            MessageBoxA(0, "驱动加载失败,可能是权限不够. 参考UAC权限设置.或者是被安全软件拦截. 如果是在64位系统下返回此错误，需要安装补丁KB3033929\n", "", MB_OK);
            break;
        }
        case -4:
        case -5:
        case -6:
        {
            MessageBoxA(0, "异常错误\n", "", MB_OK);
            break;
        }
        case -7:
        {
            MessageBoxA(NULL, "一般是系统版本不支持导致,用winver可以查看系统内部版本号. 驱动只支持正式发布的版本，所有预览版本都不支持.\n", "", MB_OK);
            break;
        }
      }
        return ret;
    }

    long
    Dmsoft::BindWindowEx(long hwnd,
                         std::wstring display,
                         std::wstring mouse,
                         std::wstring keypad,
                         std::wstring pu,
                         long mode)
    {
      return m_dm->qWgKzCkrMIo(
        hwnd, display.c_str(), mouse.c_str(), keypad.c_str(), pu.c_str(), mode);
    }

    long Dmsoft::GetDmCount()
    {
        return m_dm->iBlikUQt();
    }

    long
    Dmsoft::SetPath(std::wstring path)
    {
      return m_dm->lelxiTTDu(path.c_str());
    }

    long Dmsoft::UnBindWindow()
    {
        return m_dm->eztP();
    }

    long Dmsoft::LockInput(long lock)
    {
        return m_dm->eWGSsDYMxx(lock);
    }

    long Dmsoft::KeyDown(long vk_code)
    {
        return m_dm->ueWMluyylll(vk_code);
    }

    long Dmsoft::KeyPress(long vk_code)
    {
        return m_dm->bIPxtRSe(vk_code);
    }

    long Dmsoft::KeyUp(long vk_code)
    {
        return m_dm->mrbYLFr(vk_code);
    }

    long Dmsoft::LeftClick()
    {
        return m_dm->RiWTlLsGxXAxbW();
    }

    long Dmsoft::LeftDoubleClick()
    {
        return m_dm->EYGvZ();
    }

    long Dmsoft::LeftDown()
    {
        return m_dm->XsDLBt();
    }

    long Dmsoft::LeftUp()
    {
        return m_dm->ZVoluwPhx();
    }

    long Dmsoft::MoveR(long rx, long ry)
    {
        return m_dm->QPwLaLXE(rx, ry);
    }

    long Dmsoft::MoveTo(long x, long y)
    {
        return m_dm->SlgA(x, y);
    }

    std::wstring
    Dmsoft::MoveToEx(long x, long y, long w, long h)
    {
      return (const wchar_t*)m_dm->jUFxBUEZ(x, y, w, h);
    }

    long
    Dmsoft::FindMultiColor(long x1,
                           long y1,
                           long x2,
                           long y2,
                           std::wstring first_color,
                           std::wstring offset_color,
                           double sim,
                           long dir,
                           long& intX,
                           long& intY)
    {
        VARIANT intX_ = { 0 }, intY_ = {0};
        long ret = m_dm->HQHDGzrdCCZAhxP(x1,
                                         y1,
                                         x2,
                                         y2,
                                         first_color.c_str(),
                                         offset_color.c_str(),
                                         sim,
                                         dir,
                                         &intX_,
                                         &intY_);
        intX = intX_.lVal;
        intY = intY_.lVal;
        return ret;
    }

    long long
    Dmsoft::ReadInt(long hwnd, std::wstring addr, long type)
    {
      return m_dm->fGgDBtzu(hwnd, addr.c_str(), type);
    }

    std::wstring
    Dmsoft::ReadString(long hwnd, std::wstring addr, long type, long len)
    {
      return (const wchar_t*)m_dm->WRatR(hwnd, addr.c_str(), type, len);
    }

    float
    Dmsoft::ReadFloat(long hwnd, std::wstring addr)
    {
      return m_dm->ofoEcnebatya(hwnd, addr.c_str());
    }

    double
    Dmsoft::ReadDouble(long hwnd, std::wstring addr)
    {
      return m_dm->FoEHMtHxoZS(hwnd, addr.c_str());
    }

    long long Dmsoft::VirtualAllocEx(long hwnd, long long addr, long size, long type)
    {
        return m_dm->pLwQvUeF(hwnd, addr, size, type);
    }

    long
    Dmsoft::WriteFloat(long hwnd, std::wstring addr, float v)
    {
      return m_dm->zekVPxatol(hwnd, addr.c_str(), v);
    }

    long
    Dmsoft::WriteData(long hwnd, std::wstring addr, std::wstring data)
    {
      return m_dm->lZrcjRXCTyBTn(hwnd, addr.c_str(), data.c_str());
    }

    std::wstring
    Dmsoft::IntToData(long long value, long type)
    {
      return (const wchar_t*)m_dm->kkhgiY(value, type);
    }

    long long
    Dmsoft::GetModuleBaseAddr(long hwnd, std::wstring module)
    {
      return m_dm->stHJCFYxrMM(hwnd, module.c_str());
    }

    long Dmsoft::SetWindowState(long hwnd, long flag)
    {
        return m_dm->CxpFENSLixLZvAu(hwnd, flag);
    }

    long Dmsoft::MoveWindow(long hwnd, long x, long y)
    {
        return m_dm->pyRMWmA(hwnd, x, y);
    }

    long
    Dmsoft::FindWindow(std::wstring className, std::wstring title)
    {
      return m_dm->lKZNLLekQMAV(className.c_str(), title.c_str());
    }

    long
    Dmsoft::SendString(long hwnd, std::wstring str)
    {
      return m_dm->jVkb(hwnd, str.c_str());
    }

    long Dmsoft::GetWindowProcessId(long hwnd)
    {
        return m_dm->hNYBtURZ(hwnd);
    }

    std::wstring
    Dmsoft::EnumWindowByProcess(std::wstring process_name,
                                std::wstring title,
                                std::wstring class_name,
                                long filter)
    {
      return (const wchar_t*)m_dm->mCdMp(
        process_name.c_str(), title.c_str(), class_name.c_str(), filter);
    }

    std::wstring
    Dmsoft::Assemble(long long base_addr, long is_64bit)
    {

      return (const wchar_t*)m_dm->lsHvILCRipdRbwY(base_addr, is_64bit);
    }

    long
    Dmsoft::AsmAdd(std::wstring asm_ins, ...)
    {
      wchar_t strInfo[1024] = { 0 };
      va_list arg_ptr;
      va_start(arg_ptr, asm_ins);
      vswprintf_s(strInfo, 1024, asm_ins.c_str(), arg_ptr);
      va_end(arg_ptr);
      return m_dm->LkYIDRkVfJTJ(strInfo);
    }

    long Dmsoft::AsmClear()
    {
        return m_dm->wutdDQyrIDfLa();
    }

    long long Dmsoft::AsmCall(long hwnd, long mode)
    {
        return  m_dm->EmizmgUgWLnqosC(hwnd, mode);
    }

    long long
    Dmsoft::AsmCallEx(long hwnd, long mode, std::wstring base_addr)
    {
      return m_dm->gcKS(hwnd, mode, base_addr.c_str());
    }

    std::wstring
    Dmsoft::ReadIni(std::wstring section, std::wstring key, std::wstring file)
    {
      return (const wchar_t*)m_dm->xyADnWX(
        section.c_str(), key.c_str(), file.c_str());
    }

    long
    Dmsoft::WriteIni(std::wstring section,
                     std::wstring key,
                     std::wstring value,
                     std::wstring file)
    {
      return m_dm->NxVEvWnmN(
        section.c_str(), key.c_str(), value.c_str(), file.c_str());
    }

    long
    Dmsoft::WriteFile(std::wstring file, std::wstring content)
    {
      return m_dm->hMDHgMJwwUKIXD(file.c_str(), content.c_str());
    }

    std::wstring
    Dmsoft::GetMachineCode()
    {
      return (const wchar_t*)m_dm->InHZIkxJxkBMqi();
    }

    unsigned __int64
    Dmsoft::QWORD(unsigned __int64 地址)
    {
      wchar_t addr[1024] = { 0 };
      swprintf_s(addr, L"%llx", 地址);
      return ReadInt(m_hwnd, addr, 3);
    }

    unsigned __int64
    Dmsoft::QWORD(std::wstring 地址, ...)
    {

      wchar_t strInfo[1024] = { 0 };
      va_list arg_ptr;
      va_start(arg_ptr, 地址);
      vswprintf_s(strInfo, 1024, 地址.c_str(), arg_ptr);
      va_end(arg_ptr);
      return ReadInt(m_hwnd, strInfo, 3);
    }

    unsigned long
    Dmsoft::DWORD(unsigned __int64 地址)
    {
      wchar_t addr[1024] = { 0 };
      swprintf_s(addr, L"%llx", 地址);
      return (unsigned long)ReadInt(m_hwnd, addr, 0);
    }

    unsigned long
    Dmsoft::DWORD(std::wstring 地址, ...)
    {
      wchar_t strInfo[1024] = { 0 };
      va_list arg_ptr = NULL;
      va_start(arg_ptr, 地址);
      vswprintf_s(strInfo, 1024, 地址.c_str(), arg_ptr);
      va_end(arg_ptr);
      return (unsigned long)ReadInt(m_hwnd, strInfo, 4);
    }

    float
    Dmsoft::Float(unsigned __int64 地址)
    {
      wchar_t addr[1024] = { 0 };
      swprintf_s(addr, L"%llx", 地址);
      return ReadFloat(m_hwnd, addr);
    }

    float
    Dmsoft::Float(std::wstring 地址, ...)
    {
      wchar_t strInfo[1024] = { 0 };
      va_list arg_ptr = NULL;
      va_start(arg_ptr, 地址);
      vswprintf_s(strInfo, 1024, 地址.c_str(), arg_ptr);
      va_end(arg_ptr);
      return ReadFloat(m_hwnd, strInfo);
    }

    std::wstring
    Dmsoft::GBK(unsigned __int64 地址, long 长度)
    {
      wchar_t addr[1024] = { 0 };
      swprintf_s(addr, 1024, L"%llx", 地址);
      return ReadString(m_hwnd, addr, 0, 长度);
    }

    std::wstring
    Dmsoft::Unicode(unsigned __int64 地址, long 长度)
    {
      wchar_t addr[1024] = { 0 };
      swprintf_s(addr, 1024, L"%llx", 地址);
      return ReadString(m_hwnd, addr, 1, 长度);
    }

    std::wstring
    Dmsoft::UTF8(unsigned __int64 add, long len)
    {
      wchar_t addr[1024] = { 0 };
      swprintf_s(addr, 1024, L"%llx", add);
      return ReadString(m_hwnd, addr, 2, len);
    }

    BYTE
    Dmsoft::BYTE(unsigned __int64 地址)
    {
      wchar_t addr[1024] = { 0 };
      swprintf_s(addr, L"%llx", 地址);
      return (unsigned char)ReadInt(m_hwnd, addr, 2);
    }

    Dmsoft& Dmsoft::初始()
    {
        m_x = 0;
        m_y = 0;
        m_ret = true;
        return *this;
    }

    //Dmsoft&
    //Dmsoft::查找(SColor& Color)
    //{
    //    long ret = FindMultiColor(Color.x1, Color.x2, Color.x2, Color.y2, Color.颜色.c_str(), Color.偏移颜色.c_str(), Color.相似度, Color.方向, m_x, m_y);
    //    if (ret == 1)
    //    {
    //        m_ret = true;
    //    }
    //    else
    //    {
    //        m_ret = false;
    //    }
    //    return *this;
    //}

    Dmsoft& Dmsoft::左键点击()
    {
        if (m_ret)
        {
            MoveTo(m_x + 3, m_y + 3);
            Sleep(50);
            LeftClick();
        }
        return *this;
    }

    Dmsoft&
    Dmsoft::左键点击(SPoint zb)
    {
        if (m_ret)
        {
            MoveToEx((long)zb.x, (long)zb.y, 3, 3);
            Sleep(50);
            LeftClick();
        }
        return *this;
    }

    Dmsoft&
    Dmsoft::发送字符串(long hwnd, std::wstring str)
    {
      if (m_ret) {
        SendString(hwnd, str.c_str());
      }
      return *this;
    }

    Dmsoft&
    Dmsoft::按键(long 键码, size_t 次数, long 延时)
    {
        if (m_ret)
        {
            for (size_t i = 0; i < 次数; i++)
            {
                KeyPress(键码);
                Sleep(延时);
            }

        }
        return *this;
    }

    Dmsoft& Dmsoft::延时(long 毫秒)
    {
        if (m_ret)
        {
            Sleep(毫秒);
        }
        return *this;
    }

}
