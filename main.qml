import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Window {
    visible: true
    title: qsTr("Sample Traffic Counter")
    width: 1600
    height: 600
    property alias rdButtons: rdButtons
        ColumnLayout{
            id: outerLayout
                    GroupBox {
                        id: logGroup
                        Layout.fillWidth: true
                        title: "log"
                        RowLayout {
                            //Layout.alignment: AlignTop
                            id: rowLayout
                            anchors.fill: parent
                            TextField {
                                id: mainLog
                                text: "Log"
                                Layout.fillWidth: true
                                enabled: false
                            }
                            Button {
                                text: "Open folder..."
                                id: buttonOpen
                                onClicked: {
                                    videoDirectoryDialog.open()
                                }
                            }
                            Button {
                                text: "Preview Video"
                                id: buttonPreview
                                enabled: false
                                onClicked: {
                                    trafficCounter.initializePipeline()
                                }
                                Connections
                                {
                                     target: VideoFileManager
                                     onUrlsNotEmpty: {
                                        console.log("Urls not empty, enabling preview button")
                                        buttonPreview.enabled = true
                                     }
                                }
                            }

                            FileDialog {
                                id: videoDirectoryDialog
                                title: "Videos directory"
                                folder: "file:///C:/Videos/"
                                selectFolder:  true
                                onAccepted: {
                                    VideoFileManager.populateUrls(videoDirectoryDialog.fileUrl)
                                    RoadDrawer.setRoadCfgPath(videoDirectoryDialog.fileUrl)
                                }
                                onRejected: {
                                    console.log("Canceled")
                                }

                            }
                        }
                    }
                    GroupBox {
                        id: frameAndDrawing
                        RowLayout {
                            anchors.fill: parent
                            Layout.alignment: Qt.AlignTop
                            ColumnLayout{
                                    Text {
                                        id: labelPreview
                                        text: qsTr("Video preview:")
                                    }
                                    Rectangle {
                                        id:rectRoadDrawing
                                        width: 640; height: 360
                                        color: "gray"
                                        MouseArea{
                                            anchors.fill: parent
                                            onClicked: {
                                              // RoadDrawer.setCornerCoordinates(mouseX,mouseY)
                                               //OctopusCam.redrawRoad()
                                            }
                                        }
                                        Image {
                                            id: frameBox
                                        }
                                        Connections
                                        {
                                            target: FrameProvider
                                            onQimagesReady: {
                                                frameBox.source =  "image://images/o" + Math.random()
                                                console.log("qimagesReady signal");
                                            }
                                        }
                                    }
                            }
                            ColumnLayout{
                                    id: rdButtons
                                    property var number: 1
                                    Layout.fillWidth: false
                                    ExclusiveGroup {
                                        id: roadDrawingGroup
                                        onCurrentChanged: {
                                            //RoadDrawerCam1.setSelectedCorner(current.test)

                                        }
                                    }
                                    Text {
                                        id: rdTitle
                                        text: qsTr("Select corner:")

                                    }
                                    RadioButton {
                                        text: "top left"
                                        checked: true
                                        exclusiveGroup: roadDrawingGroup
                                        property var test: 0
                                    }
                                    RadioButton {
                                        text: "top right"
                                        exclusiveGroup: roadDrawingGroup
                                        property var test: 1
                                    }
                                    RadioButton {
                                        text: "bottom right"
                                        exclusiveGroup: roadDrawingGroup
                                        property var test: 2
                                    }
                                    RadioButton {
                                        text: "bottom left"
                                        property var test: 3
                                        exclusiveGroup: roadDrawingGroup

                                    }
                                    Button{
                                        text: "load points";

                                    }
                                    Button{
                                        text: "save points";
                                        //onClicked: //RoadDrawerCam1.saveRoadData();
                                    }

                                    Button{
                                        text: "find homography"
                                       // onClicked: //OctopusCam1.roadSelected()
                                    }

                                    Text{
                                        text: "frame:"
                                    }
                                    TextField{
                                        id: cam1FrameNumber
                                        //onAccepted: // OctopusCam1.setCamFrameTo(cam1FrameNumber.text)
                                    }
                                    Button{
                                        text: "set"
                                       // onClicked: //OctopusCam1.setCamFrameTo(cam1FrameNumber.text)
                                    }

                            }
                            ColumnLayout{
                                    Text {
                                        id: labelHomography
                                        text: qsTr("Road homography")

                                    }
                                    Rectangle {
                                        id:rectHomography
                                        width: 200; height: 400
                                        color: "gray"
                                        Image {
                                             id: homographyImage
                                             //source: "image://frameprovidercam1/homography_"

                                        }

                                   }
                            }
                            ColumnLayout{
                                visible: false;
                                    Text {
                                        id: labelForeground
                                        text: qsTr("Foreground")

                                    }
                                    Rectangle {
                                        id: rectForeground
                                        width: 200; height: 400
                                        color: "gray"
                                        Image {
                                             id: foregroundImage
                                             //source: "image://frameprovidercam1/f_"

                                        }

                                   }
                            }
                            ColumnLayout{
                                    Text {
                                        id: labelTracking
                                        text: qsTr("Car tracking")

                                    }
                                    Rectangle {
                                        id: rectTracking
                                        width: 200; height: 400
                                        color: "gray"
                                        Image {
                                             id: trackingImage
                                             //source: "image://frameprovidercam1/t_"

                                        }

                                   }
                            }
                            ColumnLayout{
                                Layout.fillHeight: parent
                                Text{
                                    text: "Tracking log"
                                }

                                TextArea{
                                    Layout.fillHeight: parent

                                    id:trackingLogCam1

                                   // height: 400

                                }

                            }

                        }
                    }
        }

}
