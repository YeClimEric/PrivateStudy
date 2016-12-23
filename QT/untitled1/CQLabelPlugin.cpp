#include "CQLabel.h"
#include "CQLabelPlugin.h"

#include <QtPlugin>

CQLabelPlugin::CQLabelPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void CQLabelPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool CQLabelPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *CQLabelPlugin::createWidget(QWidget *parent)
{
    return new CQLabel(parent);
}

QString CQLabelPlugin::name() const
{
    return QLatin1String("CQLabel");
}

QString CQLabelPlugin::group() const
{
    return QLatin1String("");
}

QIcon CQLabelPlugin::icon() const
{
    return QIcon();
}

QString CQLabelPlugin::toolTip() const
{
    return QLatin1String("");
}

QString CQLabelPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool CQLabelPlugin::isContainer() const
{
    return false;
}

QString CQLabelPlugin::domXml() const
{
    return QLatin1String("<widget class=\"CQLabel\" name=\"cQLabel\">\n</widget>\n");
}

QString CQLabelPlugin::includeFile() const
{
    return QLatin1String("CQLabel.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(cqlabelplugin, CQLabelPlugin)
#endif // QT_VERSION < 0x050000
