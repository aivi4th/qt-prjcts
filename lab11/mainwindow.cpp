#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(ui->view);
    ui->view->setScene(scene);
    color=Qt::white;
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_rectangle_clicked()
{
    QGraphicsRectItem* rectangle=new QGraphicsRectItem(QRect(0,0,40,20));
     rectangle->setBrush(color);
     rectangle->setFlags(QGraphicsItem::ItemIsMovable);
     scene->addItem(rectangle);
}
void MainWindow::on_ellipse_clicked()
{
    QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(QRect(0,0,40,20));
    ellipse->setBrush(color);
    scene->addItem(ellipse);
    ellipse->setFlags(QGraphicsItem::ItemIsMovable);
}
void MainWindow::on_color_clicked()
{
    color = QColorDialog::getColor();
}
void MainWindow::on_save_clicked(){
    QString name= QFileDialog::getSaveFileName(this,"Сохранить", QCoreApplication::applicationDirPath(), "BMP Files (*.bmp);;JPEG (*.JPEG);;PNG (*.png)" );
        if (!name.isNull())
        {
            QPixmap image = this->ui->view->grab();
            image.save(name);
        }
}
void MainWindow::on_load_clicked()
{
    QString name = QFileDialog::getOpenFileName(this,tr("Открыть"),QDir::currentPath());
    scene->addPixmap(QPixmap(name));
}
