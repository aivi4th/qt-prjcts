#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QGraphicsView>
#include<QGraphicsItem>
#include<QColorDialog>
#include<QPainter>
#include<QImage>
#include<QFileDialog>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QColor color;
private slots:
        void on_rectangle_clicked();
        void on_ellipse_clicked();
        void on_color_clicked();
        void on_save_clicked();
        void on_load_clicked();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};
#endif // MAINWINDOW_H
