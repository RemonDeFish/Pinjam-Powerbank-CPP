#include <QGuiApplication>
#include <QQmlApplicationEngine>

// TAMBAHAN: Masukkan dua pustaka ini
#include <QQmlContext>
#include "loanmanager.h"

int main(int argc, char *argv[])
{
    // Baris ini tetap dibiarkan jika kamu masih memakai Virtual Keyboard
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // TAMBAHAN: Buat objek LoanManager dan daftarkan dengan nama "backend"
    LoanManager manager;
    engine.rootContext()->setContextProperty("backend", &manager);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("Pinjam_Powerbank", "Main");

    return QCoreApplication::exec();
}