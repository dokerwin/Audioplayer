#include "appcore.h"
#include "playlist.h"
#include "datatracks.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
 #include <QtWebView>
#include "loader.h"
#include "playlistplgn.h"
int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  Loader as;
  as.playlist_toJobject();


  QGuiApplication app(argc, argv);

  AppCore appCore; // Create the application core with signals and slots

  QQmlApplicationEngine engine;
  QQmlContext *context = engine.rootContext();

  /* We load the object into the context to establish the connection,
   * and also define the name "appCore" by which the connection will occur
   * */
  context->setContextProperty("appCore", &appCore);
  context->setContextProperty("_myModel", &appCore.getPlaylist().getModel());
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
  Qt::QueuedConnection);
  engine.load(url);



  return app.exec();
}
