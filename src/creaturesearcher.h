#ifndef CREATURESEARCHER_H
#define CREATURESEARCHER_H

#include <QTableView>
#include <QSqlTableModel>
#include <QMap>

#include "loadingscreen.h"

class QStandardItemModel;
class Creature;
class CreatureModelCreature;
class QSqlDatabase;
class QStandardItem;
class ProxyModel;
class CreatureSearcher : public QTableView
{
    Q_OBJECT
public:
    CreatureSearcher(QWidget* parent, const QSqlDatabase& db, LoadingScreen& ls);
public slots:
    void Search(const QString& s);
    void SetZoneFilter( const QString& s);
    void OnlyEventAI(bool on);

signals:
    void entrySelected(uint entry, QString name);

private slots:
    void onActivated(const QModelIndex& idx);

private:
    QStandardItemModel* model;
    ProxyModel* proxyModel;
    QMap<int,CreatureModelCreature*> creatures;
    QList<CreatureModelCreature*> creatureslst;
    void Load(LoadingScreen& ls);
};

#endif // CREATURESEARCHER_H
