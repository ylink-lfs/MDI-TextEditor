#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_interface.h"
#include <QFileInfo>

//Design sucks...I should have use one class inherit from QTextEdit to override the closeEvent...
//Anyway, just implement the mainWindow's close event, and do better at next time

class main_interface : public QMainWindow
{
	Q_OBJECT

public:
	main_interface(QWidget *parent = Q_NULLPTR);

private:
	Ui::main_interfaceClass ui;
	unsigned filename_id;
	QMap<QMdiSubWindow*, QFileInfo> window_name;

	QString get_grouped_file_filter() const;
	QString get_diversed_file_filter() const;
	QString get_default_filename();
	void validate_action();
	void save_and_close();
protected:
	void closeEvent(QCloseEvent* event) override;
public slots:
	//menuFile items
	void on_actionNew_triggered();
	void on_actionOpen_triggered();
	void on_actionSave_triggered();
	void on_actionSave_As_triggered();
	void on_actionExit_triggered();

	//menuEdit items
	void on_actionUndo_triggered();
	void on_actionRedo_triggered();
	void on_actionCut_triggered();
	void on_actionCopy_triggered();
	void on_actionPaste_triggered();

	//menuWindow items
	void on_actionShut_Current_Window_triggered();
	void on_actionShut_All_Windows_triggered();
	void on_actionPrevious_triggered();
	void on_actionNext_triggered();

	//menuHelp items
	void on_actionAbout_triggered();
	void on_actionAbout_Qt_triggered();
};