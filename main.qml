import QtQuick 2.1
import QtQuick.Window 2.1

Window {
    id: page
    visible: true
    width: 360
    height: 360
    color: "#969b3b"




    Flickable {

            anchors.fill: parent
            transformOrigin: Item.Bottom
            boundsBehavior: Flickable.DragOverBounds
            flickableDirection: Flickable.HorizontalAndVerticalFlick
            contentHeight: 35
            contentWidth: 35

            Rectangle{
                x: 163
                y: 325
                width: 35
                height: 35
                color: "#c94343"
                radius: 16
                border.width: 3
                border.color: "#0b0b0b"

        }
    }

}
