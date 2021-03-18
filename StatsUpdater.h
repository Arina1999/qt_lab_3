#ifndef ABSTRACTUPDATER_H
#define ABSTRACTUPDATER_H

#include <functional>
#include <QString>

/*!
 * \brief The StatsUpdater class это моё видение
 * шаблонного метода и адаптера -- я считаю, что
 * можно обойтись без наследования, в данной задаче оно избыточно
 *
 * Я бы даже просто завела словарь с std::function в главном окне,
 * но этот класс - пустышка выделяет идею
 */
class StatsUpdater
{
public:
    StatsUpdater(std::function<void(const QString& path)> updater)
        : updater_(std::move(updater))
    { }

    void doUpdate(const QString& path) {
        updater_(path);
    }

private:
    std::function<void(const QString& path)> updater_;
};

#endif // ABSTRACTUPDATER_H
