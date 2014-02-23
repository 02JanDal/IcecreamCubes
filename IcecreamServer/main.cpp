#include <QCoreApplication>

#include <QCommandLineParser>
#include <QDir>
#include <QThread>

#include "Logging.h"
#include "AIManager.h"
#include "CacheManager.h"
#include "EntityManager.h"
#include "NetworkManager.h"
#include "PermissionManager.h"
#include "PhysicsManager.h"
#include "PluginManager.h"
#include "SaveManager.h"

#include "config.h"

class InputHandler : public QThread
{
	Q_OBJECT
public:
	explicit InputHandler() : QThread()
	{
		stream = new QTextStream(stdin);
	}
	QTextStream *stream;

	void run()
	{
		while (true)
		{
			const QString str = stream->readLine();
			if (str.isEmpty())
			{
				continue;
			}
			emit command(str);
		}
	}

signals:
	void command(const QString &cmd);
};

void cleanup()
{
	delete AI::AIManager::instance;
	delete Cache::CacheManager::instance;
	delete Entities::EntityManager::instance;
	delete Network::NetworkManager::instance;
	delete Permissions::PermissionManager::instance;
	delete Physics::PhysicsManager::instance;
	delete Plugins::PluginManager::instance;
	delete Saves::SaveManager::instance;
}

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	app.setApplicationName("Icecream Server");
	app.setApplicationVersion(ICECREAM_SERVER_VERSION);
	app.setOrganizationName("Jan Dalheimer");

	QLoggingCategory::installFilter(&loggingFilter);
	qInstallMessageHandler(&messageHandler);
	qAddPostRoutine(&cleanup);

	QCommandLineParser parser;
	parser.setApplicationDescription(QObject::tr("The default server implementation for the Icecream voxel game"));
	parser.addHelpOption();
	parser.addVersionOption();
	parser.addOption(QCommandLineOption("pluginspath", "Path to the plugins folder", "PATH", "plugins/"));
	parser.addOption(QCommandLineOption("configspath", "Path to the configs folder", "PATH", "configs/"));
	parser.addOption(QCommandLineOption("save", "Path to the save to load", "PATH"));
	parser.addOption(QCommandLineOption("singleplayer", "Only the specified user may join", "USER"));
	parser.addOption(QCommandLineOption("port", "Set an explicit port", "PORT", "0"));
	parser.process(app);

	if (!parser.isSet("save"))
	{
		qCCritical(LOG_GENERAL) << "You need to specify a save";
		parser.showHelp(-1);
	}
	if (parser.isSet("port"))
	{
		bool ok = true;
		parser.value("port").toLongLong(&ok);
		if (!ok)
		{
			qCCritical(LOG_GENERAL) << "The specified port is not parsable as an integer";
			parser.showHelp(-1);
		}
	}

	QObject *root = new QObject;

	AI::AIManager::instance = new AI::AIManager(root);
	Cache::CacheManager::instance = new Cache::CacheManager(root);
	Entities::EntityManager::instance = new Entities::EntityManager(root);
	Network::NetworkManager::instance = new Network::NetworkManager(root, parser.value("port").toLongLong(), parser.value("singleplayer"));
	Permissions::PermissionManager::instance = new Permissions::PermissionManager(root);
	Physics::PhysicsManager::instance = new Physics::PhysicsManager(root);
	Plugins::PluginManager::instance = new Plugins::PluginManager(root, QDir(parser.value("pluginspath")));
	Saves::SaveManager::instance = new Saves::SaveManager(root, QDir(parser.value("save")));
	qCDebug(LOG_GENERAL) << "All managers ready";

	InputHandler *inputHandler = new InputHandler;
	QObject::connect(inputHandler, &InputHandler::command, [](const QString &cmd)
	{
		Permissions::PermissionManager::instance->command(QString(), cmd);
	});
	inputHandler->start();

	Plugins::PluginManager::instance->discoverPlugins();
	Network::NetworkManager::instance->startServer();
	qCDebug(LOG_GENERAL) << "Init done. Running server";
	int ret = app.exec();
	qCDebug(LOG_GENERAL) << "Shutting down";
	return ret;
}

#include "main.moc"
