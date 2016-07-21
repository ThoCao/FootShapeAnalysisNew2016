#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QtWidgets/qplaintextedit.h>
#include <QScrollBar>
#include <qapplication.h>

class LogViewer:public QPlainTextEdit
{
	
	Q_OBJECT
public:


	explicit LogViewer(QWidget* parent=0):QPlainTextEdit(parent){}
	~LogViewer(void){}

public:
	void Log(const char* log, const char* color="black", int style=0){
		QString s;
		s.append(style==1? "<b>":
		style==2?"<i>":
		style==3?"<b><i>":"");
		s.append("<font color=\"");
		s.append(color);
		s.append("\">");
		s.append(log);
		s.append("</font>");
		s.append(style==1? "</b>":
		style==2?"</i>":
		style==3?"</b></i>":"");
		appendHtml(s);
		verticalScrollBar()->setSliderPosition(
			verticalScrollBar()->maximum());
		qApp->processEvents();	
	}
	void Log(QString& log, const char* color="black", int style=0){
		QString s;
		s.append(style==1? "<b>":
		style==2?"<i>":
		style==3?"<b><i>":"");
		s.append("<font color=\"");
		s.append(color);
		s.append("\">");
		s.append(log);
		s.append("</font>");
		s.append(style==1? "</b>":
		style==2?"</i>":
		style==3?"</b></i>":"");
		appendHtml(s);	
		verticalScrollBar()->setSliderPosition(
			verticalScrollBar()->maximum());
		qApp->processEvents();	
	}

	void Log(const QString& log, const char* color="black", int style=0){
		QString s;
		s.append(style==1? "<b>":
		style==2?"<i>":
		style==3?"<b><i>":"");
		s.append("<font color=\"");
		s.append(color);
		s.append("\">");
		s.append(log);
		s.append("</font>");
		s.append(style==1? "</b>":
		style==2?"</i>":
		style==3?"</b></i>":"");
		appendHtml(s);	
		verticalScrollBar()->setSliderPosition(
			verticalScrollBar()->maximum());
		qApp->processEvents();	
	}
};

