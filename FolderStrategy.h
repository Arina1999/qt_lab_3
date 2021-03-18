#ifndef FOLDERSTRATEGY_H
#define FOLDERSTRATEGY_H

#include "AbstractStrategy.h"
#include <QHash>

class FolderStrategy : public AbstractStrategy
{
public:
    void CalcStatistics(const QString& path);

protected:
    void traverseByType(const QString &path, QHash<QString, qint64> &hash) ;
};

#endif // FOLDERSTRATEGY_H
