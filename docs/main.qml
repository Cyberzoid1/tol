import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 800
    height: 480
    title: qsTr("Hello World")

    MainForm {
        anchors.fill: parent
        mouseArea1.onClicked: {
            if( rectangle1.x == 300 )
            {
                rectangle1.x = 50
                rectangle2.x = 300
                rectangle3.opacity = 0.0
            }
            else if( rectangle1.x == 550 )
            {
                rectangle1.x = 300
                rectangle3.x = 50
                rectangle2.opacity = 1.0
            }

        }
        mouseArea2.onClicked: {
            if( rectangle1.x == 300 )
            {
                rectangle1.x = 550
                rectangle3.x = 300
                rectangle2.opacity = 0.0
            }
            else if( rectangle1.x == 50 )
            {
                rectangle1.x = 300
                rectangle2.x = 550
                rectangle3.opacity = 1.0
            }
        }
        mouseArea3.onClicked: {
            if( rectangle1.x == 300 )
            {
                rectangle1.x = 550
                rectangle3.x = 300
                rectangle2.opacity = 0.0
                rectangle1.opacity = 1.0
                rectangle3.opacity = 1.0
            }
            else
            {
                rectangle1.x = 550
                rectangle3.x = 300
                rectangle2.opacity = 0.0
                rectangle1.opacity = 1.0
                rectangle3.opacity = 1.0
            }
        }
        mouseArea4.onClicked: {
            if( rectangle1.x == 50 )
            {
                rectangle1.x = 300
                rectangle2.x = 550
                rectangle3.x = 50
                rectangle3.opacity = 1.0
                rectangle2.opacity = 1.0
                rectangle1.opacity = 1.0
            }
            else if( rectangle1.x == 550 )
            {
                rectangle1.x = 300
                rectangle3.x = 50
                rectangle2.x = 550
                rectangle2.opacity = 1.0
                rectangle1.opacity = 1.0
                rectangle3.opacity = 1.0
            }
            else
            {
                rectangle1.x = 300
                rectangle3.x = 50
                rectangle2.x = 550
                rectangle2.opacity = 1.0
                rectangle1.opacity = 1.0
                rectangle3.opacity = 1.0
            }
        }
        mouseArea5.onClicked: {
            if( rectangle1.x = 300 )
            {
                rectangle1.x = 50
                rectangle2.x = 300
                rectangle3.opacity = 0.0
                rectangle1.opacity = 1.0
                rectangle2.opacity = 1.0
            }
            else
            {
                rectangle1.x = 50
                rectangle1.x = 300
                rectangle3.opacity = 0.0
                rectangle1.opacity = 1.0
                rectangle2.opacity = 1.0
            }
        }

        //mouseArea.onClicked: {
          //  console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        //}
    }


}

/*Item {
    Rectangle {
        width: 200
        height: 320
        color: white
        border.width: 1
    }
}*/
