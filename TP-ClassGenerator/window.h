#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QObject>
#include <QString>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QDateEdit>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QPushButton>

class window : public QWidget {
    Q_OBJECT
public slots:
    void generateFiles();
    void enableCommentaries();
    void enableToSetInheritor();
public:
    window();
    ~window();
private:
    QVBoxLayout *m_vBoxLayout;
    QVBoxLayout *m_definitionLayout;
    QVBoxLayout *m_parametersLayout;
    QVBoxLayout *m_commentariesLayout;

    QFormLayout *m_definitionFormLayout;
    QFormLayout *m_commentariesFormLayout;

    QGroupBox *m_definitionGroupBox;
    QGroupBox *m_parametersGroupBox;
    QGroupBox *m_commentariesGroupBox;

    QCheckBox *m_inheritedCheckBox;
    QCheckBox *m_protectionCheckBox;
    QCheckBox *m_defaultConstructorCheckBox;
    QCheckBox *m_destructorCheckBox;
    QCheckBox *m_commentariesCheckBox;

    QLineEdit *m_name;
    QLineEdit *m_inheritOf;
    QLineEdit *m_authorName;

    QTextEdit *m_commentaries;

    QDateEdit *m_creationDate;

    QPushButton *m_pushButton;

};

#endif // WINDOW_H
