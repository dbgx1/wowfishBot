#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtabqtableviewmodel.h"
#include <QMainWindow>
#include <QTimer>
QT_BEGIN_NAMESPACE
  namespace Ui { class MainWindow; }
QT_END_NAMESPACE

  class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

  QTabQTableViewModel* m_jsModel = 0;
  QTimer* m_timer = 0;

  void timerEvent(QTimerEvent* event);

private:
  Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
