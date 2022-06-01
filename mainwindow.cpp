#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "context.h"
#include "dm.h"
#include <QDebug>
#pragma execution_character_set("utf-8")
MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    m_jsModel = new QTabQTableViewModel();
    m_timer = new QTimer(this);

    dm::Dmsoft::Unzip();
    dm::Dmsoft* pdm = dm::Dmsoft::createObject();
    if (pdm->RegEx(L"aa3284965367e5c620a637778d08b9107102bbd4584", L"") == 1) {

        connect(
            m_timer, &QTimer::timeout, m_jsModel, &QTabQTableViewModel::updataWindow);
    }

    m_timer->start(1000);
    ui->tableViewJs->setModel(m_jsModel);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::timerEvent(QTimerEvent* event)
{
    switch (event->timerId()) {
    case 0x1: {

        break;
    }
    }
}
