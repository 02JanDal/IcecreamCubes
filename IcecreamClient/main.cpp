#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlContext>

#include "ClientNetworkManager.h"
#include "ResourceCacheManager.h"

#include "Window.h"
#include "ClientLogging.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
	Q_INIT_RESOURCE(resources);

	QLoggingCategory::installFilter(&loggingFilter);
	qInstallMessageHandler(&messageHandler);

	QObject *root = new QObject();

	Network::ClientNetworkManager::instance = new Network::ClientNetworkManager(root);
	GUI::ResourceCacheManager::instance = new GUI::ResourceCacheManager(root);

	GUI::Window::instance = new GUI::Window();
	QQmlContext *rootContext = GUI::Window::instance->engine()->rootContext();
	rootContext->setContextProperty("Network", Network::ClientNetworkManager::instance);
	rootContext->setContextProperty("Resources", GUI::ResourceCacheManager::instance);
	rootContext->setContextProperty("RootWindow", GUI::Window::instance);
	QObject::connect(GUI::Window::instance->engine(), &QQmlEngine::quit, &app, &QGuiApplication::quit);

	GUI::Window::instance->setSource(QUrl("qrc:/qml/main.qml"));
	GUI::Window::instance->setResizeMode(GUI::Window::SizeRootObjectToView);
	GUI::Window::instance->resize(640, 480);
	GUI::Window::instance->show();

	return app.exec();
}
