#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pSupport = new support();
    uart = new uartThread(pSupport);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    IWT_CMD cmd;
    cmd.cmd = "*IDN?\r\n";
    uart->setState(SET_PARAMETER, cmd);
}

void MainWindow::on_pushButton_2_clicked()
{
    IWT_CMD cmd;
    cmd.cmd = ":ASK:SAMPLE\r\n";
    uart->setState(SET_PARAMETER, cmd);
}
