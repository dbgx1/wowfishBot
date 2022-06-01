#include "qtabqtableviewmodel.h"
#include <QDebug>
#pragma execution_character_set("utf-8")
QTabQTableViewModel::QTabQTableViewModel()
{
    m_dm = dm::Dmsoft::createObject();
}

QModelIndex
QTabQTableViewModel::index(int row, int column, const QModelIndex& parent) const
{
    return createIndex(row, column);
}

QModelIndex
QTabQTableViewModel::parent(const QModelIndex& child) const
{
    return QModelIndex();
}

int QTabQTableViewModel::rowCount(const QModelIndex& parent) const
{
    return m_array.size();
}

int QTabQTableViewModel::columnCount(const QModelIndex& parent) const
{
    return 2;
}

QVariant
QTabQTableViewModel::data(const QModelIndex& index, int role) const
{
    int rwo = index.row();
    if (role == Qt::DisplayRole && m_array.size() > 0) {

        switch (index.column()) {
        case 0x1: {
            qDebug() << m_array[index.row()]->m_state;
            return m_array[index.row()]->m_state;
        }
        case 0x0: {
            return QVariant((int)(m_array[index.row()]->m_hwnd));
        }
        }
    }

    return QVariant();
}

QVariant QTabQTableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0x0: {
            return QVariant("窗口");
        }
        case 0x1: {
            return QVariant("状态");
        }
        }
    }

    return QVariant();
}

void QTabQTableViewModel::updataWindow()
{
    layoutChanged();
    QString strHwnd = QString::fromStdWString(
        m_dm
            ->EnumWindowByProcess(
                L"WowClassic.exe", L"魔兽世界", L"GxWindowClass", 2 + 8 + 16)
            .c_str());

    QStringList strArray = strHwnd.split(",");
    for (auto v : strArray) {
        if (!CheckRepetition(v.toInt())) {
            context* c = new context(v.toInt());
            c->start();
            m_array.push_back(c);
            beginInsertRows(QModelIndex(), rowCount(), rowCount() + 1);
            insertRow(rowCount());
            endInsertRows();
        }
    }
}

bool QTabQTableViewModel::CheckRepetition(long hwnd)
{
    for (auto v : m_array) {
        if (v->m_hwnd == hwnd) {
            return true;
        }
    }
    return false;
}
