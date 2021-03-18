#include <QApplication>
#include <QDebug>
#include <QFileInfo>

#include "FileStrategy.h"
#include "FolderStrategy.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileStrategy strat1;
    FolderStrategy strat2;

    qDebug() << DIR;
    strat1.CalcStatistics(DIR);
    strat2.CalcStatistics(DIR);

    auto res1 = strat1.GetStats();
    qInfo() << "File Strategy: \n";
    for (const auto& item : res1.keys()) {
        qInfo() << QFileInfo(item).filePath() << " : " << res1[item];
    }

    auto res2 = strat2.GetStats();
    qInfo() << "\nFolder Strategy: \n";
    for (const auto& item : res2.keys()) {
        qInfo() << item << " : " << res2[item];
    }

    return a.exec();
}
