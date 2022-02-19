#include "engine.h"

void Engine::set_speed(Parametr *value, int time_mksec){
    if(value->value != value->end_param){
        value->speed= (value->end_param - value->value)/time_mksec;
        timer25fps.start(FRAME);
    }
}

Q_INVOKABLE  void Engine::setMode(int value){
    m_mode = value;
    switch(m_mode){
        case 0:
            break;
        case 1:{ // Запуск двигателя
            int work_time = 3*1000;
            Pa.end_param = Pa.value - 5;
            Pg.end_param = 1;
            RPM.end_param = 400;

            for(int i = 0;i<3; i++){
                mas[i]->time = work_time;
                set_speed(mas[i],work_time);
            }
        }
            break;
        case 2:{// rpm up
            if(RPM.value <= 1600){
                RPM.time = 5*1000;
                RPM.end_param += 10;
                set_speed(&RPM,RPM.time);

            }
        }
            break;
        case 3:{// rpm down
            if(RPM.value >= 400){
                RPM.time = 2*1000;
                RPM.end_param -= 10;
                set_speed(&RPM,RPM.time);
            }
        }
            break;
        case 4:{
            RPM.end_param = 0;
            RPM.time = RPM.value/100 * 1000;
            RPM.speed = -0.1;
            Pg.time =Pg.value * 2 * 1000;
            Pg.end_param = 0;
            set_speed(&Pg,Pg.time);

        } break;
    }

    emit modeChange();
}


void Engine::timeRanOut(){
    static int interval = 1;

    for(int i = 0;i<3; i++){
        if(mas[i]->time > 0){
            mas[i]->value += mas[i]->speed*FRAME;
            mas[i]->time -= FRAME;
            qDebug()<<mas[i]->value; /// проверка значений RPM
        }
        interval += FRAME;
    }
    if(Pa.value <= 0) qDebug()<<"Oxygen empty";

}
