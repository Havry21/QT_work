#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <qqml.h>
#include <QTimer>
#include <QTime>

#define FRAME 40

struct Parametr{
    float value;
    float speed;
    float end_param;
    int time;
};

class Engine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int mode READ getMode WRITE setMode NOTIFY modeChange)
    QML_ELEMENT

public:

    Engine(){
        QObject::connect(&timer25fps, SIGNAL(timeout()), this, SLOT(timeRanOut()));
        Pa.value = 16;
        Pg.value = 0;
        RPM.value = 0;
    }

    QTimer timer25fps;

    int getMode(){ return m_mode;}

Q_INVOKABLE void button(){ qDebug()<<m_mode;}
Q_INVOKABLE  void setMode(int value);

signals:
    void modeChange();
private slots:
    void timeRanOut();

private:
    void set_speed(Parametr *value, int time_sec);
    int m_mode = 0;
    int work_time;
    Parametr Pa;
    Parametr Pg;
    Parametr RPM;
    Parametr *mas[3] = {&Pa,&Pg,&RPM}; //
};


#endif // ENGINE_H
