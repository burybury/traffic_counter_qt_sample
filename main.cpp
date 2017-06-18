#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <trafficcounter.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("applicationDirPath", QGuiApplication::applicationDirPath());

    TrafficCounter trafficCounter{};
    trafficCounter.initializeView(engine);
    engine.rootContext()->setContextProperty("trafficCounter",&trafficCounter);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
