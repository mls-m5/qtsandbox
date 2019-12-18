// Example by Mattias Larsson Sköld

#include <QWidget>
#include <QPainter>
#include <QApplication>

class Widget : public QWidget
{
//    Q_OBJECT // use does not work when included in main file like this

public:

    void paintEvent(QPaintEvent *e) override {
        QWidget::paintEvent(e);
        QPainter painter(this);
        painter.setPen(QColor(0,0,0));

        QFont font = painter.font();
        font.setPixelSize(48);
        painter.setFont(font);
        painter.drawText(0, 100, "hej");

        painter.drawLine(0, 0, 100, 100);

        QTransform transform;

        transform.rotate(30);

        painter.setTransform(transform);
    }

    Widget(QWidget *parent = nullptr)
        : QWidget(parent)
    {
    }
    ~Widget() override
    {
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
