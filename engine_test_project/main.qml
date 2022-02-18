import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Engine 1.0

Window {
    id: win
    width: 1553
    height: 1168
    visible: true
    title: qsTr("Hello World")


    Image {
        width: win.width
        height: win.height
        source: "qrc:/img/back.png"

    }

    Engine{
        id: engine
    }

    Image {
        id: press_gaz_arrow
        width: 33; height: 58
        x: 1185; y: 330
        source: "qrc:/img/arrow.png"
    }

    Image {
        id: press_oil_arrow
        width: 33; height: 58
        x: 1360; y: 330
        source: "qrc:/img/arrow.png"
    }

    Text{
        id: rpm_num

    }

    Item {
        id: controll_button

        signal mode(type: int)

        Button{
            id: button1
            width: 175; height: 215
            text: "Start"
            x: 134; y: 187
            onClicked: engine.set_mode = 1;

        }

        Button{
            id: button2
            width: 175; height: 215
            text: engine.set_mode
            x: 1286; y: 513
            onClicked: engine.set_mode = 2;

        }

        Button{
            id: button3
            width: 175; height: 215
            text: "Stop"
            x: 73; y: 683
            onClicked: engine.set_mode = 3;

        }
    }

    Item{
        id: rpm_control
        property int  w: 41
        property int  h: 34

        Button{
            id: rpm_up
            width: rpm_control.w; height: rpm_control.h
            text: "inc"
            x: 1276; y: 970

        }
        Button{
            id: rpm_down
            width: rpm_control.w; height: rpm_control.h
            text: "dec"
            x: 1323; y: 970

        }
    }




}

