#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QString>
#include <qqml.h>

class Engine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int mode READ mode()  WRITE set_mode NOTIFY mode_change)
    QML_ELEMENT

public:
    //explicit Engine(QObject *parent = nullptr);
    int mode();
    void set_mode(const &mode);
signals:
    void mode_change();

private:
    int m_mode = 0;
};


#endif // ENGINE_H
