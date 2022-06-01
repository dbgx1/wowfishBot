#ifndef QTABQTABLEVIEWMODEL_H
#define QTABQTABLEVIEWMODEL_H

#include "context.h"
#include "dm.h"
#include <QAbstractItemModel>
class QTabQTableViewModel : public QAbstractItemModel {
    Q_OBJECT

public:
    QTabQTableViewModel();
    std::vector<context*> m_array;
    dm::Dmsoft* m_dm = 0;

    QModelIndex index(int row,
        int column,
        const QModelIndex& parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex& child) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role = Qt::DisplayRole) const;

public slots:
    //
    void updataWindow();
    //检查重复
    bool CheckRepetition(long hwnd);
};

#endif // QTABQTABLEVIEWMODEL_H
