#ifndef MODALWINDOW_H
#define MODALWINDOW_H

#include <QApplication>
#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QFont>
#include <QFileDialog>
#include <QString>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QTextEdit>
#include <QPushButton>

class modalwindow : public QDialog{

    Q_OBJECT

private slots:
    void saveFiles();

public:
    modalwindow(QString &cppText, QString &hText, QWidget *ptr);
    ~modalwindow();
private:
    QTabWidget *m_tabWidget;

    QWidget *m_CppFile;
    QWidget *m_HFile;

    QVBoxLayout *m_vBoxLayout;
    QVBoxLayout *m_CppFileLayout;
    QVBoxLayout *m_HFileLayout;

    QTextEdit *m_CppText;
    QTextEdit *m_HText;

    QPushButton *m_pushButton;
    QPushButton *m_saveFiles;
};

#endif // MODALWINDOW_H
