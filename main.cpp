#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication app(argc,argv);

	qDebug() << "42";

	return app.exec();
}