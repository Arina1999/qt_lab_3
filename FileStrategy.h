#ifndef FILESTRATEGY_H
#define FILESTRATEGY_H

#include "AbstractStrategy.h"
#include <QVector>
#include <QHash>

class FileStrategy : public AbstractStrategy
{
public:
    void CalcStatistics(const QString& path) override;

protected:
    void traverseByName(const QString &path, QHash<QString, qint64> &hash) ;
};

#endif // FILESTRATEGY_H
