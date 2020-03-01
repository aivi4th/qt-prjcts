#include <QtDataVisualization>
#include <QFile>
#include <cmath>
using namespace QtDataVisualization;
int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    Q3DSurface surface;
    surface.setFlags(surface.flags() ^ Qt::FramelessWindowHint);
    QSurfaceDataArray *data = new QSurfaceDataArray;
    QSurfaceDataRow *dataRow = new QSurfaceDataRow;
    QFile points("C:\\Users\\Kosinus\\Documents\\lab10\\Points.txt");
    points.open(QIODevice::WriteOnly);
    QTextStream stream(&points);
    double x = 0, y = 0, z = 0;
    for (double i = 0; i < 3.14; i+=0.15)
    {
        for (double j = -3.14; j < 0; j+=0.15)
        {
            x=sin(i)*cos(j);
            y=sin(i)*sin(j);
            z=(log(tan(i/2))+cos(i));
            stream << x << " " << z << " " << y << "\n";
        }
    stream << "\n";
    }
    points.close();
    points.open(QIODevice::ReadOnly);
    QString temp;
    while (!stream.atEnd())
    {
        stream.readLineInto(&temp);
        if (temp.length() > 0)
        {
            QTextStream coord(&temp);
            coord >> z;
            coord >> x;
            coord >> y;
            *dataRow << QVector3D(z, x, y);
        }
        else
        {
            *data << dataRow;
            dataRow = new QSurfaceDataRow;
        }
    }
    QSurface3DSeries *series = new QSurface3DSeries;
    series->dataProxy()->resetArray(data);
    surface.addSeries(series);
    surface.axisX()->setRange(-1, 1);
    surface.axisY()->setRange(0, 1);
    surface.axisZ()->setRange(-1, 1);
    QLinearGradient gr;
    gr.setColorAt(0.0, QColor(0,0,0));
    gr.setColorAt(0.0, QColor(0,0,0));
    gr.setColorAt(0.0, QColor(0,0,0));
    surface.seriesList().at(0)->setBaseGradient(gr);
    surface.seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
    surface.show();
    surface.setWindowState(Qt::WindowMaximized);
         points.close();
    return app.exec();
}
