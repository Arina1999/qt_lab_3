#include "FileStrategy.h"

#include <QDir>
#include <QFileInfo>
#include <algorithm>
#include <numeric>

#include <QDebug>

void FileStrategy::traverseByName(const QString &path, QHash<QString, qint64> &hash)
{
    QDir folder(path);
    for(auto &it : folder.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot
                                                 | QDir::Hidden | QDir::NoSymLinks, QDir::Type)) {
        if (it.isDir()) {
            traverseByName(it.absoluteFilePath(), hash);
        } else {
            hash[it.absoluteFilePath()] = QFileInfo(it.absoluteFilePath()).size();
        }
    }
}

void FileStrategy::CalcStatistics(const QString &path)
{
    QHash<QString, qint64> sizes;
    traverseByName(path, sizes);

    auto vals = sizes.values();
    qint64 total = std::accumulate(vals.begin(), vals.end(), 0);

    stats_.clear();
    for (const auto &name : sizes.keys()) {
        stats_[name] = 1. * sizes[name] / total;
    }
}

