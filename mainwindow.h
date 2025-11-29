#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    // On préparera le slot du bouton ici plus tard
    void on_boutonLancer_clicked();

private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H