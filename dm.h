#ifndef DM_H
#define DM_H
#include "aa328496536.tlh"
#include <Windows.h>
#include <string>
#include <initializer_list> 

namespace dm {
struct SPoint
{
  SPoint(float x, float y)
  {
    this->x = x;
    this->y = y;
  }
  float x = 0;
  float y = 0;
};
struct SColor
{
  long x1 = 0;
  long y1 = 0;
  long x2 = 0;
  long y2 = 0;
  std::wstring first_color;
  std::wstring offset_color;
  double 相似度 = 0.9;
  long 方向 = 0;
  SColor(long x1,
         long y1,
         long x2,
         long y2,
         std::wstring first_color,
         std::wstring offset_color,
         double 相似度 = 0.9,
         long 方向 = 0)
  {
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
    this->first_color = first_color;
    this->offset_color = offset_color;
    this->相似度 = 相似度;
    this->方向 = 方向;
  }
};

class Dmsoft
{
public:
  Iqwert* m_dm = NULL;
  long m_hwnd = 0;
  long m_x = 0;
  long m_y = 0;
  bool m_ret = true;

public:
  Dmsoft();
  ~Dmsoft();
  // reg_code 字符串: 注册码. (从大漠插件后台获取)
  //  电信线路 "121.204.252.143|121.204.253.161|125.77.165.62|125.77.165.131"
  //  联通线路 "123.129.231.44|123.129.231.45|123.129.231.85|123.129.231.86"
  long RegEx(std::wstring reg_code,
             std::wstring ver_info = L"",
             std::wstring ip =
               L"121.204.252.143|121.204.253.161|125.77.165.62|125.77.165.131");

  long Reg(std::wstring reg_code, std::wstring ver_info);
  //获得大漠对象
  static Dmsoft* createObject();
  void setHwnd(long hwnd);
  static bool Unzip();

  long DmGuard(long enable, std::wstring type);
  long BindWindowEx(long hwnd,
                    std::wstring display,
                    std::wstring mouse,
                    std::wstring keypad,
                    std::wstring pu,
                    long mode);

  //键鼠
  long KeyDown(long vk_code);
  long KeyPress(long vk_code);
  long KeyUp(long vk_code);
  long LeftClick();
  long LeftDoubleClick();
  long LeftDown();
  long LeftUp();
  long MoveR(long rx, long ry);
  long MoveTo(long x, long y);
  std::wstring MoveToEx(long x, long y, long w, long h);

  //图色
  long FindMultiColor(long x1,
                      long y1,
                      long x2,
                      long y2,
                      std::wstring first_color,
                      std::wstring offset_color,
                      double sim,
                      long dir,
                      long& intX,
                      long& intY);

  //基本设置
  long GetDmCount();
  long SetPath(std::wstring path);
  std::wstring Ver();
  //后台设置
  long UnBindWindow();
  long LockInput(long lock);
  //内存
  long long ReadInt(long hwnd, std::wstring addr, long type);
  std::wstring ReadString(long hwnd, std::wstring addr, long type, long len);
  float ReadFloat(long hwnd, std::wstring addr);
  double ReadDouble(long hwnd, std::wstring addr);
  long long VirtualAllocEx(long hwnd, long long addr, long size, long type);
  long WriteFloat(long hwnd, std::wstring addr, float v);
  long WriteData(long hwnd, std::wstring addr, std::wstring data);
  std::wstring IntToData(long long value, long type);
  long long GetModuleBaseAddr(long hwnd, std::wstring module);

  //窗口
  long SetWindowState(long hwnd, long flag);
  long MoveWindow(long hwnd, long x, long y);
  long FindWindow(std::wstring className, std::wstring title);
  long SendString(long hwnd, std::wstring str);
  long GetWindowProcessId(long hwnd);
  std::wstring EnumWindowByProcess(std::wstring process_name,
                                   std::wstring title,
                                   std::wstring class_name,
                                   long filter);

  //汇编
  std::wstring Assemble(long long base_addr, long is_64bit);
  long AsmAdd(std::wstring, ...);
  long AsmClear();
  long long AsmCall(long hwnd , long mode);
  long long AsmCallEx(long hwnd, long mode, std::wstring base_addr);

  //文件
  std::wstring ReadIni(std::wstring section,
                       std::wstring key,
                       std::wstring file);
  long WriteIni(std::wstring section,
                std::wstring key,
                std::wstring value,
                std::wstring file);
  long WriteFile(std::wstring file, std::wstring content);

  //系统
  std::wstring GetMachineCode();
  //自定义
  unsigned __int64 QWORD(unsigned __int64 add);
  unsigned __int64 QWORD(std::wstring ADD, ...);
  unsigned long DWORD(unsigned __int64 add);
  unsigned long DWORD(std::wstring add, ...);
  float Float(unsigned __int64 add);
  float Float(std::wstring add, ...);
  std::wstring GBK(unsigned __int64 add, long len = 0);
  std::wstring Unicode(unsigned __int64 add, long len = 0);
  std::wstring UTF8(unsigned __int64 add, long len = 0);
  BYTE BYTE(unsigned __int64 add);
  Dmsoft& 初始();
  //Dmsoft& 查找(SColor& 色点);
  Dmsoft& 左键点击();
  Dmsoft& 左键点击(SPoint zb);
  Dmsoft& 发送字符串(long hwnd, std::wstring str);
  Dmsoft& 按键(long 键码, size_t 次数 = 1, long 延时 = 50);
  Dmsoft& 延时(long 毫秒);

  bool operator()() { return m_ret; }
  bool operator==(bool z) { return m_ret == z; }
};
}

#endif // DM_H
