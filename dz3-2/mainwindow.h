#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QString>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
        void on_open_clicked();
        void on_info_clicked();
        void on_font_clicked();
        void on_exit_clicked();
private:
    Ui::MainWindow *ui;
    void loadTextFile(const QString &fileName);
};
#endif // MAINWINDOW_H
