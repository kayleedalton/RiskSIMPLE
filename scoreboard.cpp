#include "scoreboard.h"

Scoreboard::Scoreboard(QListView *view) : QObject(), listView(view) {  // Call QObject constructor
    model = new QStringListModel();  // No parent needed here
    listView->setModel(model);
}

void Scoreboard::updateScoreboard(const std::vector<Territory> &territories) {
    QStringList scoreList;

    for (const Territory &territory : territories) {
        QString scoreEntry = QString("Territory %1: Owner: Player %2, Troops: %3, Adjacent: %4")
        .arg(territory.id)
            .arg(territory.owner)
            .arg(territory.troops)
            .arg(QString::number(territory.adjacent.size()));

        scoreList.append(scoreEntry);
    }

    model->setStringList(scoreList);
}
