import QtQuick 2.5

Rectangle {
    //property alias mouseArea: mouseArea
   // property alias textEdit: textEdit
    property alias mouseArea1: mouseArea1
    property alias rectangle1: rectangle1
    property alias rectangle2: rectangle2
    property alias rectangle3: rectangle3
    property alias mouseArea2: mouseArea2
    property alias mouseArea3: mouseArea3
    property alias mouseArea4: mouseArea4
    property alias mouseArea5: mouseArea5
    property alias mouseArea6: mouseArea6
    property alias mouseArea7: mouseArea7
    //property alias image2: image2
    //property alias imago: imago
    width: 800
    height: 500
    //property alias mouseArea4: mouseArea4

    /*MouseArea {
        id: mouseArea
        width: 50
        height: 50
        anchors.bottomMargin: 394
        anchors.leftMargin: 48
        anchors.rightMargin: 487
        anchors.topMargin: 20
        anchors.fill: parent
    } */

    /* TextEdit {
        id: textEdit
        y: 20
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            anchors.rightMargin: -10
            anchors.bottomMargin: -10
            anchors.leftMargin: -10
            anchors.topMargin: -10
            border.width: 1
        }
    } */

    Rectangle {
        id: rectangle1
        x: 300
        y: 100
        width: 200
        height: 320
        color: "white"
        border.color: "black"
        border.width: 1

        Text {
            id: text2
            x: 80
            y: -20
            color: "#3b3b3b"
            text: qsTr("2/3")
            font.pixelSize: 12
        }
        Grid {
            columns: 10
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }

        }


    }

    MouseArea {
        id: mouseArea1
        x: 505
        y: 220
        width: 40
        height: 40

        Rectangle {
            id: rectangle5
            x: 0
            y: 0
            width: 40
            height: 40
            color: "#700f0f"
            opacity: 1.0

            /*Image {
                id: image2
                x: 0
                y: 0
                width: 40
                height: 40
                z: 1
                source: "../../Pictures/Arrow next.png"
            }*/
        }

    }

    Rectangle {
        id: rectangle2
        x: 550
        y: 100
        width: 200
        height: 320
        color: "white"
        border.color: "black"
        border.width: 1

        Text {
            id: text3
            x: 80
            y: -20
            color: "#3b3b3b"
            text: qsTr("3/3")
            font.pixelSize: 12
        }
        Grid {
            columns: 10
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
        }
    }

    MouseArea {
        id: mouseArea2
        x: 255
        y: 220
        width: 40
        height: 40


        Rectangle {
            id: rectangle4
            x: 0
            y: 0
            width: 40
            height: 40
            color: "#6e0303"
            opacity: 1.0

            /*Image {
                id: imago
                x: 0
                y: 0
                width: 40
                height: 40
                z: 1
                source: "../../Pictures/Arrow previous.png"
            } */
        }
    }

    Rectangle {
        id: rectangle3
        x: 50
        y: 100
        width: 200
        height: 320
        color: "white"
        border.color: "black"
        border.width: 1
        Text {
            id: text1
            x: 80
            y: -20
            color: "#3b3b3b"
            text: qsTr("1/3")
            font.pixelSize: 12
        }
        Grid {
            columns: 10
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
            Rectangle { height: 20; width: 20; color: "white"; border.width: 1 }
        }
    }

    Rectangle {
        id: rectangle6
        x: 50
        y: 8
        width: 700
        height: 50
        color: "#ffffff"
        Grid {
            Rectangle { id: a; width: 20; height: 50; color: "white"; border.width: 1; border.color: "black"

                MouseArea {
                    id: mouseArea3
                    x: 0
                    y: 0
                    width: 20
                    height: 50
                } }
            Rectangle { id: b; width: 20; height: 50; color: "white"; border.width: 1; border.color: "black"

            MouseArea {
                id: mouseArea4
                width: 20
                height: 50
            } }
            Rectangle { id: c; width: 20; height: 50; color: "white"; border.width: 1; border.color: "black"

            MouseArea {
                id: mouseArea5
                width: 20
                height: 50
            } }
        }
    }

    MouseArea {
        id: mouseArea6
        x: 300
        y: 430
        width: 60
        height: 60
    }

    MouseArea {
        id: mouseArea7
        x: 440
        y: 430
        width: 60
        height: 60
    }
}
