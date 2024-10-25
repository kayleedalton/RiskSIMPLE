#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <vector>
#include "territory.h"
#include "scoreboard.h" // Include the scoreboard header


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleTurnAction();

private:
    Scoreboard *scoreboard;
    Ui::MainWindow *ui;
    QStringListModel *model;
    QStringList logList;

    // Game state variables
    int playerTurn;  // 1 or 2
    int currentPhase;  // 0 = Reinforcement, 1 = Attack, 2 = Fortify


    std::vector<Territory> territories;  // All territories in the game

    void initializeGame();
    void updateLog(const QString &message);
    void processReinforcement(const QString &input);
    void processAttack(const QString &input);
    void processFortify(const QString &input);
    void transferOwnership(int territoryId, int newOwner);
};

#endif // MAINWINDOW_H
