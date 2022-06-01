#include "gameObject.h"
#include "baseData.h"

gameObject::gameObject(dm::Dmsoft* pdm , unsigned long long node)
{
	m_dm = pdm;
	m_nodeObj = node;
	m_obj = pdm->QWORD(node + 0x18);
	m_id.id1 = pdm->QWORD(node + 0x8);
	m_id.id2 = pdm->QWORD(node + 0x10);
	m_suoShuId.id1 = pdm->QWORD(m_obj + GUISHUID);
	m_suoShuId.id2 = pdm->QWORD(m_obj + GUISHUID +8);
	m_type = pdm->BYTE(m_obj + 0x10);
}

void gameObject::printGameObj()
{
	//printf("m_nodeObj:%llx obj:%llx id:%llx | %llx type:%d name:%s\n", m_nodeObj , m_obj, m_id.id1, m_id.id2, m_type , getName().c_str());
}

std::wstring
gameObject::getName()
{
  std::wstring ret;
  switch (m_type) {
    case 0x8: {
      ret = m_dm->UTF8(
        m_dm->QWORD(L"[%llx+%x]+%x", m_obj, NAME_TYPE8, NAME_TYPE8_1));
      break;
    }
    default:
      return L"";
  }

  return ret;
}

SPoint gameObject::getPoint()
{
	SPoint zb;
	if (m_obj == 0) return SPoint();
	if (m_type == 8)
	{
          zb.x = m_dm->Float(L"%llx", m_obj + FISHPOINT);
          zb.y = m_dm->Float(L"%llx", m_obj + FISHPOINT + 4);
          zb.z = m_dm->Float(L"%llx", m_obj + FISHPOINT + 8);

        }
	else
	{
          zb.x = m_dm->Float(L"[%llx+%x]+%x", m_obj, OBJPOINT, 0x20);
          zb.y = m_dm->Float(L"[%llx+%x]+%x", m_obj, OBJPOINT, 0x24);
          zb.z = m_dm->Float(L"[%llx+%x]+%x", m_obj, OBJPOINT, 0x28);
        }

	return zb;
}
