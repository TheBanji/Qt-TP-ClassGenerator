#include "window.h"
#include "modalwindow.h"

window::window() : QWidget() {
    setWindowTitle("TP - Header and CPP Files Generator");

    m_vBoxLayout = new QVBoxLayout;
    m_definitionLayout = new QVBoxLayout;
    m_parametersLayout = new QVBoxLayout;
    m_commentariesLayout = new QVBoxLayout;

    m_definitionFormLayout = new QFormLayout;
    m_commentariesFormLayout = new QFormLayout;

    m_name = new QLineEdit;
    m_inheritOf = new QLineEdit;
    m_authorName = new QLineEdit;

    m_creationDate = new QDateEdit;

    m_commentaries = new QTextEdit;

    m_inheritedCheckBox = new QCheckBox("Is the Class inherited");
    m_defaultConstructorCheckBox = new QCheckBox("Add a Default Constructor");
    m_destructorCheckBox = new QCheckBox("Add a destructor");
    m_protectionCheckBox = new QCheckBox("Add a protection against multiple inclusion");
    m_commentariesCheckBox = new QCheckBox("Add commentaries");

    m_pushButton = new QPushButton("Generate .h and .cpp");

    m_definitionGroupBox = new QGroupBox("Class's Definition");
    m_parametersGroupBox = new QGroupBox("Class Parameters");
    m_commentariesGroupBox = new QGroupBox("Commentaries");

    m_name->setInputMask("aaaaaaaaaaaaaaaaaaaa");
    m_inheritOf->setInputMask("aaaaaaaaaaaaaaaaaaa");

    m_definitionFormLayout->addRow("Name : ", m_name);
    m_definitionFormLayout->addRow(m_inheritedCheckBox, m_inheritOf);

    m_inheritOf->setDisabled(true);

    m_authorName->setDisabled(true);
    m_creationDate->setDisplayFormat("dd.MM.yyyy");
    m_creationDate->setMinimumDate(QDate::currentDate());
    m_creationDate->setDisabled(true);
    m_commentaries->setDisabled(true);

    m_definitionLayout->addLayout(m_definitionFormLayout);

    m_parametersLayout->addWidget(m_defaultConstructorCheckBox);
    m_parametersLayout->addWidget(m_destructorCheckBox);
    m_parametersLayout->addWidget(m_protectionCheckBox);

    m_commentariesFormLayout->addRow("Author : ", m_authorName);
    m_commentariesFormLayout->addRow("Creation Date : ", m_creationDate);
    m_commentariesFormLayout->addRow("Comment : ", m_commentaries);

    m_commentariesLayout->addWidget(m_commentariesCheckBox);
    m_commentariesLayout->addLayout(m_commentariesFormLayout);

    m_definitionGroupBox->setLayout(m_definitionLayout);
    m_parametersGroupBox->setLayout(m_parametersLayout);
    m_commentariesGroupBox->setLayout(m_commentariesLayout);

    m_vBoxLayout->addWidget(m_definitionGroupBox);
    m_vBoxLayout->addWidget(m_parametersGroupBox);
    m_vBoxLayout->addWidget(m_commentariesGroupBox);
    m_vBoxLayout->addWidget(m_pushButton);
    setLayout(m_vBoxLayout);

    QObject::connect(m_pushButton, SIGNAL(clicked(bool)), this, SLOT(generateFiles()));
    QObject::connect(m_commentariesCheckBox, SIGNAL(clicked(bool)), this, SLOT(enableCommentaries()));
    QObject::connect(m_inheritedCheckBox, SIGNAL(clicked(bool)), this, SLOT(enableToSetInheritor()));
}

void window::generateFiles() {
    QString cppFile;
    QString hFile;

    hFile = "//h File\n\n";
    cppFile = "//cpp File\n\n";

    if(m_name->text().isEmpty()) {
        QMessageBox::warning(this, "No name for the Class", "Please set a name to your Class.");
        return;
    }

    if(m_commentariesCheckBox->isChecked()) {
        hFile += "*\n" + m_authorName->text() + " " + m_creationDate->date().toString() +"\n" + m_commentaries->toPlainText() + "\n" + "*/\n\n";
    }
    if(m_protectionCheckBox->isChecked()) {
        hFile += "#ifndef " + m_name->text().toUpper() + "_H\n";
        hFile += "#define " + m_name->text().toUpper() + "_H\n\n";
    }

    hFile += "class " + m_name->text().toLower();

    if(m_inheritedCheckBox->isChecked()) {
        hFile += " : public " + m_inheritOf->text();
    }

    hFile += " {\n";
    hFile += "public:\n";

    if(m_defaultConstructorCheckBox->isChecked()) {
        hFile += "    " + m_name->text().toLower() + "();\n";
        cppFile += m_name->text().toLower() + "::" + m_name->text().toLower() + "() {}\n\n";
    }

    if(m_destructorCheckBox->isChecked()) {
        hFile += "    ~" + m_name->text().toLower() + "();\n";
        cppFile += m_name->text().toLower() + "::~" + m_name->text().toLower() + "() {};";
    }

    hFile += "private:\n";
    hFile += "};\n";

    if(m_protectionCheckBox->isChecked()) {hFile += "#endif";};

    modalwindow *fileWindow = new modalwindow(cppFile, hFile, this);
    fileWindow->exec();
}

void window::enableCommentaries() {
    m_commentaries->setEnabled(true);
    m_authorName->setEnabled(true);
    m_creationDate->setEnabled(true);
}

void window::enableToSetInheritor() {
    m_inheritOf->setEnabled(true);
}

window::~window() {}
