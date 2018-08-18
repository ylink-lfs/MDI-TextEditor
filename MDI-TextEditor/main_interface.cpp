#include "main_interface.h"

#include <QDialog>
#include <QMessageBox>

#include <QFileDialog>
#include <QFile>
#include <QFileInfo>

#include <QIcon>
#include <QPixMap>
#include <QLayout>
#include <QLabel>

#include <QPushButton>

#include <QMdiSubWindow>
#include <QTextEdit>
#include <QTextStream>
#include <QTextDocument>
#include <QTextFrame>

main_interface::main_interface(QWidget *parent)
	: QMainWindow(parent), filename_id(1)
{
	ui.setupUi(this);
	main_interface::setWindowTitle(QString("MDI-TextEditor"));
	validate_action();
}

void main_interface::on_actionNew_triggered()
{	
	QTextEdit* new_editor = new QTextEdit(this);
	QMdiSubWindow* new_window = ui.mdiArea->addSubWindow(new_editor);
	new_window->setWindowTitle(get_default_filename());

	new_window->show();

	validate_action();
}

void main_interface::on_actionOpen_triggered()
{
	//Use an variable for potential further edition
	QString initial_directory;

	//Get absolute directory
	QString focused_directory = QFileDialog::getOpenFileName(this, "Open a text file", initial_directory,
		get_grouped_file_filter());

	//If users click close or click "Cancel" button, an empty string will be generated. 
	//Use .isEmpty() to check
	if (focused_directory.isEmpty())
		return;

	//Get file name
	QFileInfo instance_info(focused_directory);
	QString file_name(instance_info.fileName());

	//Open file and set stream connection
	QFile focused_file_instance(focused_directory);
	focused_file_instance.open(QIODevice::ReadOnly);
	QTextStream ist(&focused_file_instance);
	
	//New an editor, name it, write into it
	QTextEdit* new_editor = new QTextEdit(this);
	QMdiSubWindow* new_window = ui.mdiArea->addSubWindow(new_editor);
	new_window->setWindowTitle(file_name);
	new_editor->setText(ist.readAll());
	new_window->show();

	validate_action();
}

void main_interface::on_actionSave_triggered()
{
	if (window_name.find(ui.mdiArea->currentSubWindow()) == window_name.end())
		on_actionSave_As_triggered();
	else
	{
		QFileInfo save_target_info(window_name[ui.mdiArea->currentSubWindow()]);
		QString save_name(save_target_info.fileName());
		QString save_path(save_target_info.absolutePath());
		QFile save_file(save_target_info.absoluteFilePath());
		save_file.open(QIODevice::Truncate | QIODevice::WriteOnly);
		QTextStream ost(&save_file);
		QMdiSubWindow* cur_subwindow = ui.mdiArea->currentSubWindow();

		//Record the approach, key word is qobject_cast
		QTextEdit* cur_edit = qobject_cast<QTextEdit*>(cur_subwindow->widget());

		//Find out why firstblock() approach is not successful
		auto block = cur_edit->document()->firstBlock();
		for (int i = 0; i < cur_edit->document()->blockCount(); i++)
		{
			ost << block.text();
			ost << '\n';
			block = block.next();
		}
	}
}

//This action will ONLY be triggered if there is one active subwindow
void main_interface::on_actionSave_As_triggered()
{
	//Use an variable for potential further edition
	QString initial_directory;
	QString save_directory = QFileDialog::getSaveFileName(this, QString("Save As"), initial_directory,
		get_diversed_file_filter());
	if (save_directory.isEmpty())
		return;

	//Get save path, save name
	QFileInfo save_target_info(save_directory);
	QString save_name(save_target_info.fileName());
	QString save_path(save_target_info.absolutePath());
	
	//Open file and set stream connection
	QFile save_file(save_directory);
	save_file.open(QIODevice::Truncate | QIODevice::WriteOnly);
	QTextStream ost(&save_file);
	
	QMdiSubWindow* cur_subwindow = ui.mdiArea->currentSubWindow();

	//Record the approach, key word is qobject_cast
	QTextEdit* cur_edit = qobject_cast<QTextEdit*>(cur_subwindow->widget());

	//Find out why firstblock() approach is not successful
	auto block = cur_edit->document()->firstBlock();
	for (int i = 0; i < cur_edit->document()->blockCount(); i++)
	{
		ost << block.text();
		ost << "\n";
		block = block.next();
	}
	if (cur_edit->document()->isModified())
	{
		cur_subwindow->setWindowTitle(save_name);
		if (window_name.find(cur_subwindow) == window_name.end())
		{
			window_name.insert(cur_subwindow, save_target_info);
		}		
	}
}

void main_interface::on_actionExit_triggered()
{
	main_interface::close();
}

void main_interface::on_actionUndo_triggered()
{
	QMdiSubWindow* cur_window = ui.mdiArea->currentSubWindow();
	QTextEdit* cur_edit = qobject_cast<QTextEdit*>(cur_window->widget());
	cur_edit->undo();
}

void main_interface::on_actionRedo_triggered()
{
	QMdiSubWindow* cur_window = ui.mdiArea->currentSubWindow();
	QTextEdit* cur_edit = qobject_cast<QTextEdit*>(cur_window->widget());
	cur_edit->redo();
}

void main_interface::on_actionCut_triggered()
{
	QMdiSubWindow* cur_window = ui.mdiArea->currentSubWindow();
	QTextEdit* cur_edit = qobject_cast<QTextEdit*>(cur_window->widget());
	cur_edit->cut();
}

void main_interface::on_actionCopy_triggered()
{
	QMdiSubWindow* cur_window = ui.mdiArea->currentSubWindow();
	QTextEdit* cur_edit = qobject_cast<QTextEdit*>(cur_window->widget());
	cur_edit->copy();
}

void main_interface::on_actionPaste_triggered()
{
	QMdiSubWindow* cur_window = ui.mdiArea->currentSubWindow();
	QTextEdit* cur_edit = qobject_cast<QTextEdit*>(cur_window->widget());
	cur_edit->paste();
}

void main_interface::on_actionShut_Current_Window_triggered()
{
	ui.mdiArea->closeActiveSubWindow();
	validate_action();
}

void main_interface::on_actionShut_All_Windows_triggered()
{
	ui.mdiArea->closeAllSubWindows();
	validate_action();
}

void main_interface::on_actionPrevious_triggered()
{
	ui.mdiArea->activatePreviousSubWindow();
}

void main_interface::on_actionNext_triggered()
{
	ui.mdiArea->activateNextSubWindow();
}

void main_interface::on_actionAbout_triggered()
{
	//Initialize about dialog
	QDialog* about_dialog = new QDialog(this);
	about_dialog->setWindowTitle("About");

	//Three script information labels
	QLabel* author_label = new QLabel("Author: ylink", about_dialog);
	author_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
	QLabel* email_label = new QLabel("E-mail: lfs@live.com", about_dialog);
	email_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
	QLabel* github_label = new QLabel("Github Alias: ylink-lfs", about_dialog);
	github_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
	QBoxLayout* script_layout = new QVBoxLayout;
	script_layout->addWidget(author_label);
	script_layout->addWidget(email_label);
	script_layout->addWidget(github_label);

	//Picture label for my avantar
	QLabel* avantar_label = new QLabel(about_dialog);
	avantar_label->setFixedSize(100, 100);
	avantar_label->setScaledContents(true);
	QPixmap avantar_body(QString(":/main_interface/images/avantar.jpg"));
	avantar_label->setPixmap(avantar_body);
	QBoxLayout* info_layout = new QHBoxLayout;
	info_layout->addWidget(avantar_label);
	info_layout->addLayout(script_layout);

	//OK button and its event
	QPushButton* ok_button = new QPushButton(about_dialog);
	ok_button->setText("OK");
	connect(ok_button, &QPushButton::pressed, about_dialog, &QDialog::close);
	QBoxLayout* main_layout = new QVBoxLayout;
	main_layout->addLayout(info_layout);
	main_layout->addWidget(ok_button);

	//Apply final layout to the dialog
	about_dialog->setLayout(main_layout);
	about_dialog->show();
}

void main_interface::on_actionAbout_Qt_triggered()
{
	QMessageBox::aboutQt(this);
}

QString main_interface::get_grouped_file_filter() const
{
	QString filter_seperate(";;");
	QString text_filter("Text(*.txt)");
	QString code_filter("Code(*.c *.cpp *.py *.htm *.html *.css *.js)");
	return text_filter + filter_seperate + code_filter;
}

QString main_interface::get_diversed_file_filter() const
{
	QString filter_seperate(";;");
	QList<QString> filter_list;
	filter_list.push_back("Text(*.txt)");
	filter_list.push_back("C Source File(*.c)");
	filter_list.push_back("C++ Source File(*.cpp)");
	filter_list.push_back("Python Source File(*.py)");
	filter_list.push_back("HTML File(*.htm)");
	filter_list.push_back("CSS File(*.css)");
	filter_list.push_back("js Source File(*.js)");
		
	QString res_filter;
	for (auto it = filter_list.begin(); it < filter_list.end(); it++)
	{
		res_filter += *it;
		if (it != filter_list.end() - 1)
		{
			res_filter += filter_seperate;
		}
	}
	return res_filter;
}

QString main_interface::get_default_filename()
{
	return QString("New" + QString::number(filename_id++));
}

void main_interface::validate_action()
{
	//If at least one QMdiSubWindow exists, then enable those actions
	if (ui.mdiArea->currentSubWindow())
	{
		ui.actionSave->setDisabled(false);
		ui.actionSave_As->setDisabled(false);
		ui.actionCopy->setDisabled(false);
		ui.actionCut->setDisabled(false);
		ui.actionPaste->setDisabled(false);
		ui.actionUndo->setDisabled(false);
		ui.actionRedo->setDisabled(false);

		ui.actionNext->setDisabled(false);
		ui.actionPrevious->setDisabled(false);
		ui.actionStacked->setDisabled(false);
		ui.actionTiled->setDisabled(false);
		ui.actionShut_All_Windows->setDisabled(false);
		ui.actionShut_Current_Window->setDisabled(false);
	}
	else
	{
		ui.actionSave->setDisabled(true);
		ui.actionSave_As->setDisabled(true);
		ui.actionCopy->setDisabled(true);
		ui.actionCut->setDisabled(true);
		ui.actionPaste->setDisabled(true);
		ui.actionUndo->setDisabled(true);
		ui.actionRedo->setDisabled(true);

		ui.actionNext->setDisabled(true);
		ui.actionPrevious->setDisabled(true);
		ui.actionStacked->setDisabled(true);
		ui.actionTiled->setDisabled(true);
		ui.actionShut_All_Windows->setDisabled(true);
		ui.actionShut_Current_Window->setDisabled(true);
	}
}

void main_interface::save_and_close()
{	
	on_actionSave_triggered();
	ui.mdiArea->currentSubWindow()->setFocus();
	on_actionShut_Current_Window_triggered();
}

void main_interface::closeEvent(QCloseEvent* event)
{	
	if (ui.mdiArea->currentSubWindow() && 
		qobject_cast<QTextEdit*>(ui.mdiArea->currentSubWindow()->widget())->document()->isModified())
	{
		QMessageBox close_box;
		close_box.setText(QString("Do you want to save your edits?"));
		close_box.addButton(QMessageBox::Yes);
		close_box.addButton(QMessageBox::No);
		close_box.addButton(QMessageBox::Cancel);
		close_box.show();
		int choice = close_box.exec();
		switch (choice)
		{
		case QMessageBox::Yes:
		{
			event->accept();
			while (ui.mdiArea->currentSubWindow())
			{
				save_and_close();
			}
			break;
		}
		case QMessageBox::No:
		{
			event->accept();
			break;
		}
		default:
		{
			event->ignore();
			break;
		}
		}
	}
	else
	{
		event->accept();
	}
	return;
}