/***************************************************************************
    qgsvaluemapconfigdlg.h
     --------------------------------------
    Date                 : 5.1.2014
    Copyright            : (C) 2014 Matthias Kuhn
    Email                : matthias at opengis dot ch
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSVALUEMAPCONFIGDLG_H
#define QGSVALUEMAPCONFIGDLG_H

#include "ui_qgsvaluemapconfigdlgbase.h"

#include "qgseditorconfigwidget.h"

#define VALUEMAP_NULL_TEXT "{2839923C-8B7D-419E-B84B-CA2FE9B80EC7}"

/** \ingroup gui
 * \class QgsValueMapConfigDlg
 * \note not available in Python bindings
 */

class GUI_EXPORT QgsValueMapConfigDlg : public QgsEditorConfigWidget, private Ui::QgsValueMapWidget
{
    Q_OBJECT

  public:
    explicit QgsValueMapConfigDlg( QgsVectorLayer* vl, int fieldIdx, QWidget* parent );
    virtual QgsEditorWidgetConfig config() override;
    virtual void setConfig( const QgsEditorWidgetConfig& config ) override;

    void updateMap( const QMap<QString, QVariant> &map, bool insertNull );

  private:
    void setRow( int row, const QString value, const QString description );

  private slots:
    void vCellChanged( int row, int column );
    void addNullButtonPushed();
    void removeSelectedButtonPushed();
    void loadFromLayerButtonPushed();
    void loadFromCSVButtonPushed();
};

#endif // QGSVALUEMAPCONFIGDLG_H
