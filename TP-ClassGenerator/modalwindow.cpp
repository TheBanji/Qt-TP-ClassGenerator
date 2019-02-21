#include "modalwindow.h"

modalwindow::modalwindow(QString &cppText, QString &hText, QWidget *ptr) : QDialog(ptr) {
    setWindowTitle("Generated Files");

    m_vBoxLayout = new QVBoxLayout;
    m_CppFileLayout = new QVBoxLayout;
    m_HFileLayout = new QVBoxLayout;

    m_tabWidget = new QTabWidget;

    m_CppFile = new QWidget;
    m_HFile = new QWidget;

    m_CppText = new QTextEdit;
    m_HText = new QTextEdit;

    m_pushButton = new QPushButton("Close Window");
    m_saveFiles = new QPushButton("Save Files");

    m_CppText->setFont(QFont("Courier"));
    m_CppText->setText(cppText);
    m_CppText->setReadOnly(true);

    m_HText->setFont(QFont("Courier"));
    m_HText->setText(hText);
    m_HText->setReadOnly(true);

    m_CppFileLayout->addWidget(m_CppText);
    m_HFileLayout->addWidget(m_HText);

    m_CppFile->setLayout(m_CppFileLayout);
    m_HFile->setLayout(m_HFileLayout);

    m_tabWidget->addTab(m_CppFile, "C++ File");
    m_tabWidget->addTab(m_HFile, "Header File");

    m_vBoxLayout->addWidget(m_tabWidget);
    m_vBoxLayout->addWidget(m_saveFiles);
    m_vBoxLayout->addWidget(m_pushButton);

    setLayout(m_vBoxLayout);

    QObject::connect(m_pushButton, SIGNAL(clicked(bool)), this, SLOT(accept()));
    QObject::connect(m_saveFiles, SIGNAL(clicked(bool)), this, SLOT(saveFiles()));
}

void modalwindow::saveFiles() {
    QString filePath = QFileDialog::getExistingDirectory(this, "Choose a directory to save your Class' File");
}

modalwindow::~modalwindow() {}
