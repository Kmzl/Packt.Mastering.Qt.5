#include "task.h"
#include "ui_task.h"
#include <QInputDialog>
#include <QDebug>

Task::Task(const QString &name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->editButton, &QPushButton::clicked, this, &Task::rename);
    connect(ui->removeButton, &QPushButton::clicked, [this, name] {
        qDebug() << "Trying to remove" <<
                    [] (const QString& taskName) -> QString {
            return "-------------" + taskName.toUpper();
        }(name);
 /*
  * []: We perfomed no capture. The lambda does not depend on the enclosing function.
  * (const QString& taskNmae): When this lambda is called, it will expect a QString to work on.
  * -> QString: The returned value of the lambda will be a QStrng.
  * return "--------" + taskNmae.toUpper(): the body of our lambda.
  * (name): Here comes the catch.Now that the lambda function is defined, we can call it pass the name parameter.
  * In a single instruction, we define it and call it.
*/
        emit removed(this);
    });

    connect(ui->checkBox, &QCheckBox::toggled, this, &Task::checked);
}

Task::~Task()
{
    qDebug() << "Destructor";
    delete ui;
}

void Task::setName(const QString &name)
{
    ui->checkBox->setText(name);
}

QString Task::name() const
{
    return ui->checkBox->text();
}

bool Task::isCompleted() const
{
    return ui->checkBox->isChecked();
}

void Task::rename()
{
    bool ok;
    QString value = QInputDialog::getText(this,
                                          tr("Edit task"),
                                          tr("Task name"),
                                          QLineEdit::Normal,
                                          this->name(),
                                          &ok);

    if (ok && !value.isEmpty())
    {
        setName(value);
    }
}


void Task::checked(bool checked)
{
    QFont font(ui->checkBox->font());
    font.setStrikeOut(checked);
    ui->checkBox->setFont(font);
    emit statusChanged(this);
}
