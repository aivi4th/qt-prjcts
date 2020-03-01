#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QFileDialog>
#include <QFontDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        QString name=":/input.txt";
        loadTextFile(name);
    }
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::loadTextFile(const QString &fileName)
    {
        QFile inputFile(fileName);
        inputFile.open(QIODevice::ReadOnly);
        QTextStream in(&inputFile);
        QString line = in.readAll();
        inputFile.close();
        ui->textEdit->setPlainText(line);
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor, 1);
    }
void MainWindow::on_open_clicked()
    {
        QString name = QFileDialog::getOpenFileName(this, tr("Открыть"), QDir::currentPath());
        loadTextFile(name);

    }
void MainWindow::on_info_clicked()
{
    int symbols=0,words=1,strings=1;
    QString text= ui->textEdit->toPlainText();
    symbols=text.length();
    for(int i = 0; i < text.length(); i++){
        if(text[i]==" ") words++;
        if(text[i]==10) {strings++; words++;}
    }
    QString name = QFileDialog::getSaveFileName(this,tr("Информация о файле"),QDir::currentPath());
    QFile out(name);
    out.open(QIODevice::WriteOnly);
    out.write("Symbols quantity = "+QString::number(symbols).toUtf8()+"\n");
    out.write("Words quantity = "+QString::number(words).toUtf8()+"\n");
    out.write("Strings quantity = "+QString::number(strings).toUtf8()+"\n");
}
void MainWindow::on_font_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok);
    ui->textEdit->setFont(font);
}
void MainWindow::on_exit_clicked()
{
    QWidget::close();
}
