#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QListView>
#include <QStringListModel>
#include <vector>
#include "territory.h"
#include <QObject>

class Scoreboard : public QObject {  // Inherit from QObject
    Q_OBJECT

public:
    Scoreboard(QListView *view);
    void updateScoreboard(const std::vector<Territory> &territories);

private:
    QStringListModel *model;
    QListView *listView;
};

#endif // SCOREBOARD_H
