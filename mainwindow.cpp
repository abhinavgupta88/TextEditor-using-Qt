
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<qfiledialog.h>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionNew_triggered()
{
    mfilename="";
    ui->textEdit->setPlainText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString file =  QFileDialog::getOpenFileName(this,"open a file");

    if(!file.isEmpty())
    {
        QFile  fil(file);
        if(fil.open(QFile::ReadOnly | QFile::Text))
        {
            mfilename=file;
            QTextStream in(&fil);
            QString text=in.readAll();
            fil.close();
            ui->textEdit->setPlainText(text);
        }
    }
}


void MainWindow::on_actionSave_triggered()
{
    QFile fil(mfilename);

    if(fil.open(QFile::WriteOnly | QFile::Text))
    {

        QTextStream out(&fil);
        out<<ui->textEdit->toPlainText();
        fil.flush();
        fil.close();

    }
}


void MainWindow::on_actionSave_As_triggered()
{
    QString file =  QFileDialog::getSaveFileName(this,"open a file");

    if(!file.isEmpty())
    {
        mfilename=file;
        on_actionSave_triggered();


    }

}


void MainWindow::on_actionCut_triggered()
{
ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
ui->textEdit->paste();
}


void MainWindow::on_actionBold_triggered()
{
QTextCharFormat format;
format.setFontWeight(QFont::Bold);

QTextCursor cursor = ui->textEdit->textCursor();
cursor.mergeCharFormat(format);
}


void MainWindow::on_actionItalic_triggered()
{
// Get the selected text from a QTextEdit widget
QTextCursor cursor = ui->textEdit->textCursor();
if (!cursor.hasSelection()) {
        return;
}
QTextCharFormat format;
format.setFontItalic(true);
cursor.mergeCharFormat(format);
}


void MainWindow::on_actionUndo_triggered()
{
ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
ui->textEdit->redo();
}


void MainWindow::on_actionResume_triggered()
{
 QDesktopServices::openUrl(QUrl::fromLocalFile("D:\Resume.pdf"));
}


void MainWindow::on_actionSuperScript_triggered()
{
QTextEdit *textEdit = ui->textEdit; // Assuming the QTextEdit widget is named "textEdit"
QTextCharFormat format;
format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
if (textEdit->textCursor().charFormat().verticalAlignment() == QTextCharFormat::AlignSuperScript) {
        // The current selection is already in superscript, so remove it
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
}
textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionSubScript_triggered()
{
QTextEdit *textEdit = ui->textEdit; // Assuming the QTextEdit widget is named "textEdit"
QTextCharFormat format;
format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
if (textEdit->textCursor().charFormat().verticalAlignment() == QTextCharFormat::AlignSubScript) {
        // The current selection is already in superscript, so remove it
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
}
textEdit->mergeCurrentCharFormat(format);
}

