#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "jeu/Partie.h" // On inclut ton jeu

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_boutonLancer_clicked()
{
    // Test simple pour voir si ça compile et link
    try {
        bool variantes[5] = { false };
        std::vector<std::string> noms = { "Joueur 1", "Joueur 2" };

        // On crée la partie via le Singleton
        Partie& p = Partie::get_instance(2, true, variantes, noms);

        QMessageBox::information(this, "Succès",
            "Partie lancée avec " + QString::number(p.getNbJoueurs()) + " joueurs !");

    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Erreur", e.what());
    }
}