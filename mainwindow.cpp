#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDir"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{


    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName();
        if (path.isEmpty())return;
        QFile file(path);
        if(file.open(QIODevice::ReadOnly))
        {
            QByteArray ba = file.readAll();
            QString text(ba);
            ui->plainTextEdit->setPlainText(text);
        }

}


void MainWindow::on_pushButton_2_clicked()
{
    QString path = QFileDialog::getSaveFileName();
        if (path.isEmpty())return;
        QFile file(path);
        if(file.open(QIODevice::WriteOnly))
        {
            QString text = ui->plainTextEdit->toPlainText();
            QByteArray ba = text.toUtf8();
            file.write(ba,ba.length());
        }


}


void MainWindow::on_pushButton_3_clicked()
{
    QFile file("./info.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);
        ui->plainTextEdit->setPlainText(text);
    }
}

